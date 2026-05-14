#include <stdio.h>
#include <string.h>
#include <assert.h>

int lengthOfLastWord(char* s){
    size_t i = 0;
    unsigned int size = 0, previous_size = 0;
    for(i=0; s[i]!='\0'; i++){
        if(s[i] == ' '){
            if(i != 0 && s[i-1]==' '){
                continue;
            }
            previous_size = size;
            size = 0;
        }
        else{
            size++;
        }
    }
    if(size == 0 && previous_size != 0){
        return previous_size;
    }
    return size;
}

void run_test(char* s, int expected, int test_num) {
    int result = lengthOfLastWord(s);
    if (result == expected) {
        printf("Test Case %d Passed\n", test_num);
    } else {
        printf("Test Case %d Failed: Input=\"%s\", Expected=%d, Got=%d\n", test_num, s, expected, result);
        assert(result == expected);
    }
}

int main() {
    run_test("Hello World", 5, 1);
    run_test("   fly me   to   the moon  ", 4, 2);
    run_test("luffy is still joyboy", 6, 3);
    run_test("a", 1, 4);
    run_test("    day", 3, 5);
    run_test("day    ", 3, 6);
    run_test("       ", 0, 7); 
    run_test("b   a    ", 1, 8);
    run_test("racecar", 7, 9);
    
    char large_input[10001];
    memset(large_input, ' ', 10000);
    large_input[10000] = '\0';
    large_input[5000] = 'z';
    run_test(large_input, 1, 10);

    printf("\nAll robust test cases passed!\n");
    return 0;
}
