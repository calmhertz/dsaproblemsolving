#include <stdio.h>
#include <string.h>

int c2i(char x){
    switch(x){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt(char* s) {
    long int ans = 0;
    int last = 0;
    size_t i = 0;
    while(s[i] != '\0'){
        int a = c2i(s[i]);
        if(a>last){
            ans -= last;
            ans += (a-last);
        }
        else{
            ans += a;
        }
        last = a;
        i++;
    }
    return ans;
}

int main() {
    struct TestCase {
        char* input;
        int expected;
        char* description;
    };

    struct TestCase tests[] = {
        {"III", 3, "Simple addition"},
        {"LVIII", 58, "Addition with multiple symbols"},
        {"IV", 4, "Single subtraction (I before V)"},
        {"IX", 9, "Single subtraction (I before X)"},
        {"XL", 40, "Single subtraction (X before L)"},
        {"XC", 90, "Single subtraction (X before C)"},
        {"CD", 400, "Single subtraction (C before D)"},
        {"CM", 900, "Single subtraction (C before M)"},
        {"MCMXCIV", 1994, "Complex mixed cases"},
        {"MMMCMXCIX", 3999, "Maximum boundary value"},
        {"MMXXVI", 2026, "Current year (addition only)"},
        {"CDXLIV", 444, "Triple subtraction case"}
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    printf("Running Roman to Integer Tests...\n");
    printf("----------------------------------\n");

    for (int i = 0; i < numTests; i++) {
        int result = romanToInt(tests[i].input);
        if (result == tests[i].expected) {
            printf("[PASS] Input: %-10s | Expected: %-4d | Got: %-4d\n", 
                   tests[i].input, tests[i].expected, result);
            passed++;
        } else {
            printf("[FAIL] Input: %-10s | Expected: %-4d | Got: %-4d (%s)\n", 
                   tests[i].input, tests[i].expected, result, tests[i].description);
        }
    }

    printf("----------------------------------\n");
    printf("Results: %d/%d passed.\n", passed, numTests);

    return (passed == numTests) ? 0 : 1;
}
