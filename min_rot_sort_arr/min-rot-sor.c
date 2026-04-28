#include <stdio.h>
#include <assert.h>

int findMin(int* nums, int numsSize){
    if(numsSize==1){
        return nums[0];
    }
    if(nums[0]<nums[numsSize-1]){
        return nums[0];
    }
    for(int i=0; i<numsSize-1; i++){
        if(nums[i]>nums[i+1]){
            return nums[i+1];
        }
    }
    return 0;
}

void run_test(const char* name, int* nums, int numsSize, int expected) {
    int result = findMin(nums, numsSize);
    if (result == expected) {
        printf("[PASSED] %s\n", name);
    } else {
        printf("[FAILED] %s | Expected: %d, Got: %d\n", name, expected, result);
    }
}

int main() {
    int t1[] = {2, 1};
    run_test("Smallest Rotated (n=2)", t1, 2, 1);

    int t2[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    run_test("Pivot near end", t2, 9, 1);

    int t3[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    run_test("Pivot at index 1", t3, 10, 1);

    int t4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    run_test("Zero rotation (Standard sorted)", t4, 10, 1);

    int t5[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 1};
    run_test("Maximum rotation (n-1)", t5, 10, 1);

    int t6[] = {5000, -5000};
    run_test("Max/Min constraint range", t6, 2, -5000);

    int t7[] = {-1, -10, -9, -8, -7, -6, -5, -4, -3, -2};
    run_test("All negative rotated", t7, 10, -10);

    int t8[5000];
    for (int i = 0; i < 5000; i++) {
        t8[i] = i - 2000; 
    }
    run_test("Large array n=5000 (No rotation)", t8, 5000, -2000);

    int t9[5000];
    int start_val = 1000;
    for (int i = 0; i < 5000; i++) {
        t9[i] = start_val++;
    }
    int temp = t9[4999];
    for (int i = 4999; i > 0; i--) {
        t9[i] = t9[i-1];
    }
    t9[0] = temp;
    run_test("Large array n=5000 (Rotated by 1)", t9, 5000, 1000);

    int t10[] = {0, 1, 2, 4, 5, 6, 7};
    run_test("Even length vs Odd length logic", t10, 7, 0);

    return 0;
}
