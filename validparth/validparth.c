#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char push_pop(char x){
    switch (x) {
        case '{':
        case '[':
        case '(':
            return '1';
            break;
        case '}':
            return '{';
            break;
        case ']':
            return '[';
            break;
        case ')':
            return '(';
            break;
        default:
            return '0';
    }
}

bool isValid(char* s) {
    int n=10, top=-1, i=0;
    char* stack = (char*)malloc(n*sizeof(char));
    while (s[i]!='\0') {
        char temp = push_pop(s[i]);
        if(temp=='1'){
            if((i+1)==n){
                n *= 1.1;
                stack = (char*)realloc(stack, n*sizeof(char));
            }
            stack[++top] = s[i];
        }
        else {
            if(top >= 0 && temp == stack[top]){
                top--;
            }
            else {
                return false;
            }
        }
        i++;
    }
    free(stack);
    if(top==-1){
        return true;
    }
    return false;
}

int main() {
    char *test_cases[] = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
        "(((((((())))))))",
        "(",
        ")",
        "}{",
        "[[[]",
        "[]]]",
        "([{}])",
        "((((((((((",
        "))))))))))",
        "[(])",
        "([]){}",
        "(([]){})",
        "{[()]}",
        "(((((((((())))))))))",
        "()()()()()()()()()()",
        "(((((((((()",
        "{{{{{{{{{{}}}}}}}}}}",
        "{{{{{{{{{{}}}}}}}}}}]"
    };

    bool expected_values[] = {
        true,  true,  false, false, true, 
        true,  false, false, false, false, 
        false, true,  false, false, false, 
        true,  true,  true,  true,  true, 
        false, true,  false
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    int passed = 0;

    for (int i = 0; i < num_tests; i++) {
        bool result = isValid(test_cases[i]);
        if (result == expected_values[i]) {
            printf("%s\n", test_cases[i]);
            printf("Test %2d Passed\n", i + 1);
            passed++;
        } else {
            printf("Test %2d Failed: %s | Expected %d, Got %d\n", i + 1, test_cases[i], expected_values[i], result);
        }
    }

    printf("\nScore: %d/%d\n", passed, num_tests);

    return 0;
}
