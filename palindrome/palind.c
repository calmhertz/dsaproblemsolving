#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    int rev=0, temp=x, r=0;
    while (temp>0) {
        rev = (rev*10)+(temp%10);
        temp /= 10;
    }
    return rev==x;
}

int main() {
    int testCases[] = {
        121,            // true
        -121,           // false (negative)
        10,             // false (trailing zero)
        0,              // true (single digit edge)
        1,              // true
        9,              // true
        11,             // true
        1001,           // true
        12321,          // true
        123321,         // true
        123421,         // false
        1000021,        // false
        2147447412,     // true (large palindrome near INT_MAX)
        -2147447412,    // false (negative version of above)
        INT_MAX,        // false (2147483647)
        INT_MIN,        // false (-2147483648)
        1463847412,     // false (reverse overflows if not careful)
        2000000002,     // true (large palindrome with zeros)
        1000000001,     // true
        1000000009,
        10
    };

    int n = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < n; i++) {
        int x = testCases[i];
        printf("Input: %d -> Output: %s\n", x,
               isPalindrome(x) ? "true" : "false");
    }

    return 0;
}
