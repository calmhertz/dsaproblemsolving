#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int a = 0;
    while (strs[0][a] != '\0') { a++; }
    if(a == 0){
        char* result = (char*)malloc(1*sizeof(char));
        result[0] = '\0';
        return result;
    }
    a++;
    char* result = (char*)malloc(a*sizeof(char));
    a = 0;
    while (strs[0][a] != '\0') { result[a]=strs[0][a]; a++; }
    result[a] = '\0';

    for(int i=1; i<strsSize; i++){
        int j = 0;
        while (result[j] != '\0') {
            if(result[j] != strs[i][j] || strs[i][j] == '\0'){
                result[j] = '\0';
                break;
            }
            j++;
        }
    }
    return result;
}

void verify(int id, char** strs, int size, char* expected) {
    char* result = longestCommonPrefix(strs, size);
    
    bool match = (strcmp(result, expected) == 0);
    
    if (match) {
        printf("Test %2d Passed: Output \"%s\"\n", id, result);
    } else {
        printf("Test %2d Failed: Expected \"%s\", Got \"%s\"\n", id, expected, result);
    }
}

int main() {
    char* t1[] = {"flower", "flow", "flight"};
    verify(1, t1, 3, "fl");

    char* t2[] = {"dog", "racecar", "car"};
    verify(2, t2, 3, "");

    char* t3[] = {"interspecies", "interstellar", "interstate"};
    verify(3, t3, 3, "inters");

    char* t4[] = {"apple", "apple", "apple"};
    verify(4, t4, 3, "apple");

    char* t5[] = {"", "b"};
    verify(5, t5, 2, "");

    char* t6[] = {"a"};
    verify(6, t6, 1, "a");

    char* t7[] = {"ab", "a"};
    verify(7, t7, 2, "a");

    char* t8[] = {"prefix", "pre", "preface", "preservation"};
    verify(8, t8, 4, "pre");

    char* t9[] = {"throne", "throne"};
    verify(9, t9, 2, "throne");

    char* t10[] = {"race", "racecar", "racetrack", "racer"};
    verify(10, t10, 4, "race");

    char* t11[] = {"", ""};
    verify(11, t11, 2, "");

    char* t12[] = {"a", "b", "c"};
    verify(12, t12, 3, "");

    char* t13[] = {""};
    verify(13, t13, 1, "");

    char* t14[] = {"a"};
    verify(14, t14, 1, "a");

    return 0;
}
