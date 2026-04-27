#include <stdio.h>
#include <assert.h>

int strStr(char* haystack, char* needle){
    if(!haystack || !needle){
        return -1;
    }
    int i=0, j=0;
    while (haystack[i]!='\0') { 
        if(haystack[i]==needle[j]){
            // check remaining
        }
    }
}

void run_tests() {
    struct TestCase {
        char* haystack;
        char* needle;
        int expected;
    } tests[] = {
        // Standard Cases
        {"sadbutsad", "sad", 0},
        {"leetcode", "leeto", -1},
        {"hello", "ll", 2},
        {"mississippi", "issip", 4},
        
        // Edge Cases: Lengths
        {"a", "a", 0},
        {"a", "b", -1},
        {"abc", "abcd", -1},
        
        // Repeated Patterns (Hard to pass for naive restarts)
        {"aaaaa", "bba", -1},
        {"aaaaa", "aaa", 0},
        {"aaaaab", "aaab", 2},
        {"mississippi", "issipi", -1},
        {"ababcabcacbab", "abcac", 5},
        
        // Overlapping potential matches
        {"mississip", "issip", 4},
        {"ababab", "abab", 0},
        
        // Single character matches
        {"aaa", "a", 0},
        {"abc", "c", 2},
        
        // Long haystack, short needle
        {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", "aaab", 48}
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < num_tests; i++) {
        int result = strStr(tests[i].haystack, tests[i].needle);
        if (result != tests[i].expected) {
            printf("Test Failed at Index %d!\n", i);
            printf("Haystack: %s | Needle: %s\n", tests[i].haystack, tests[i].needle);
            printf("Expected: %d | Got: %d\n", tests[i].expected, result);
            assert(result == tests[i].expected);
        }
    }

    printf("All test cases passed successfully.\n");
}

int main() {
    run_tests();
    return 0;
}
