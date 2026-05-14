#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int sum = 0, carry = 1;
    int* result = (int*)malloc(digitsSize*sizeof(int));
    *returnSize = digitsSize;
    int i = 0;
    for(i = *returnSize-1; i >= 0; i--){
        if(carry == 0){
            break;
        }
        sum = digits[i] + carry;
        result[i] = (sum>=10)?(sum - 10):sum;
        carry = sum / 10;
    }
    while (i>=0) {
            result[i] = digits[i];
            i--;
    }
    if(carry != 0){
        *returnSize += 1;
        result = (int*)realloc(result, *returnSize*sizeof(int));
        result[(*returnSize-1)] = 0;
        for(i = (*returnSize)-1; i>0; i--){
            result[i] = result[i-1];
        }
        result[0] = carry;
    }
    return result;
}

void run_test(int* input, int size, int* expected, int expectedSize) {
    int returnSize;
    int* result = plusOne(input, size, &returnSize);

    if (returnSize != expectedSize) {
        printf("FAILED: Expected size %d, got %d\n", expectedSize, returnSize);
        free(result);
        return;
    }

    for (int i = 0; i < returnSize; i++) {
        if (result[i] != expected[i]) {
            printf("FAILED: At index %d, expected %d, got %d\n", i, expected[i], result[i]);
            free(result);
            return;
        }
    }

    printf("PASSED\n");
    free(result);
}

int main() {
    // TC 1: All Nines (Result requires expansion)
    int t1[] = {9, 9, 9, 9, 9};
    int e1[] = {1, 0, 0, 0, 0, 0};
    run_test(t1, 5, e1, 6);

    // TC 2: Single Digit Nine (Smallest expansion)
    int t2[] = {9};
    int e2[] = {1, 0};
    run_test(t2, 1, e2, 2);

    // TC 3: Maximum Constraint Boundary (100 digits, all nines)
    int t3[100];
    int e3[101];
    for (int i = 0; i < 100; i++) t3[i] = 9;
    e3[0] = 1;
    for (int i = 1; i <= 100; i++) e3[i] = 0;
    run_test(t3, 100, e3, 101);

    // TC 4: Trailing Nines (Carry stops mid-array)
    int t4[] = {1, 2, 9, 9, 9};
    int e4[] = {1, 3, 0, 0, 0};
    run_test(t4, 5, e4, 5);

    // TC 5: Single Digit Non-Nine (Lower boundary)
    int t5[] = {0};
    int e5[] = {1};
    run_test(t5, 1, e5, 1);

    // TC 6: Alternating Carry (Complex ripple)
    int t6[] = {8, 9, 9, 9};
    int e6[] = {9, 0, 0, 0};
    run_test(t6, 4, e6, 4);

    // TC 7: Large Number with Inner Nines (No carry propagation)
    int t7[] = {1, 9, 9, 8};
    int e7[] = {1, 9, 9, 9};
    run_test(t7, 4, e7, 4);

    // TC 8: Mixed digits (Standard case)
    int t8[] = {4, 3, 2, 1};
    int e8[] = {4, 3, 2, 2};
    run_test(t8, 4, e8, 4);

    return 0;
}
