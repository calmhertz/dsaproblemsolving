#include <stdio.h>
#include <assert.h>

int searchInsert(int* nums, int numsSize, int target) {
    if(!nums){
        return 0;
    }
    int l=0, h=numsSize-1, m=0;
    while(l<=h){
        m=l+((h-l)/2);
        if(nums[m]==target){
            return m;
        }
        else if(nums[m]>target){
            h = m-1;
        }
        else {
            l = m+1;
        }
    }
    return l;
}

void run_test(int* nums, int size, int target, int expected, const char* testName) {
    int result = searchInsert(nums, size, target);
    if (result == expected) {
        printf("[PASS] %s\n", testName);
    } else {
        printf("[FAIL] %s | Expected: %d, Got: %d\n", testName, expected, result);
    }
}

int main() {
    int t1[] = {1, 3, 5, 6};
    run_test(t1, 4, 5, 2, "Standard target in middle");
    run_test(t1, 4, 2, 1, "Standard target missing (insert middle)");
    run_test(t1, 4, 7, 4, "Target greater than max");
    run_test(t1, 4, 0, 0, "Target smaller than min");

    int t2[] = {1};
    run_test(t2, 1, 1, 0, "Single element match");
    run_test(t2, 1, 0, 0, "Single element insert before");
    run_test(t2, 1, 2, 1, "Single element insert after");

    int t3[] = {1, 3};
    run_test(t3, 2, 2, 1, "Two elements insert middle");
    run_test(t3, 2, 0, 0, "Two elements insert front");
    run_test(t3, 2, 4, 2, "Two elements insert back");

    int t4[] = {1, 3, 5, 7, 9, 11};
    run_test(t4, 6, 1, 0, "Boundary: Match first");
    run_test(t4, 6, 11, 5, "Boundary: Match last");
    
    int t5[] = {-10000, -5000, 0, 5000, 10000};
    run_test(t5, 5, -10000, 0, "Negative constraints: Match min");
    run_test(t5, 5, 10001, 5, "Negative constraints: Out of upper bound");
    run_test(t5, 5, -10001, 0, "Negative constraints: Out of lower bound");

    int t6[10000];
    for(int i = 0; i < 10000; i++) t6[i] = i * 2;
    run_test(t6, 10000, 19998, 9999, "Large array: Match last");
    run_test(t6, 10000, 19999, 10000, "Large array: Insert end");
    run_test(t6, 10000, 20000, 10000, "Large array: Over limit");

    return 0;
}
