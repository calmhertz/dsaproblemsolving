#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* result = (int*)malloc(2*sizeof(int));
    if(!nums){
        result[0] = -1;
        result[1] = -1;
        return result;
    }
    if(numsSize==1){
        if(target == nums[0]){
            result[0] = 0;
            result[1] = 0;
        }
        else {
            result[0] = -1;
            result[1] = -1;
        }
        return result;
    }
    int found = -1;
    int l = 0, h = numsSize-1, mid = 0;

    while(l<=h){
        mid = l + ((h-l)/2);
        if(nums[mid]==target){
            found = mid;
            break;
        }
        else if (nums[mid]>target) {
            h = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    if(found==-1){
        result[0] = -1;
        result[1] = -1;
        return result;
    }

    int i = mid;
    while (nums[i]==target && i>=0) {
        i--;
    }

    result[0] = (i<0)?0:i+1;
    i = mid;
    while (nums[i]==target && i<=numsSize-1) {
        i++;
    }
    result[1] = (i>numsSize-1)?numsSize-1:i-1;

    return result;
}

void run_test(const char* test_name, int* nums, int numsSize, int target, int expected_start, int expected_end) {
    int returnSize;
    int* result = searchRange(nums, numsSize, target, &returnSize);
    
    if (returnSize == 2 && result[0] == expected_start && result[1] == expected_end) {
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s | Expected [%d, %d], Got [%d, %d]\n", 
               test_name, expected_start, expected_end, result[0], result[1]);
    }
    free(result);
}

int main() {
    // 1. Extreme Values: Target at INT_MIN/INT_MAX boundaries
    int t1_n[] = {INT_MIN, INT_MIN, -100, 0, 100, INT_MAX, INT_MAX};
    run_test("Boundary: INT_MIN search", t1_n, 7, INT_MIN, 0, 1);
    run_test("Boundary: INT_MAX search", t1_n, 7, INT_MAX, 5, 6);

    // 2. Large Array: All elements are the same (Stress tests the range expansion)
    int size_large = 100000;
    int* t2_n = (int*)malloc(size_large * sizeof(int));
    for(int i = 0; i < size_large; i++) t2_n[i] = 5;
    run_test("Stress: 100k identical elements", t2_n, size_large, 5, 0, size_large - 1);
    free(t2_n);

    // 3. Tight Range: Target exists but surrounded by values +/- 1
    int t3_n[] = {4, 5, 5, 5, 5, 5, 5, 6};
    run_test("Tight Range: Surrounded by +/- 1", t3_n, 8, 5, 1, 6);

    // 4. Binary Search Trap: Even vs Odd length with target at ends
    int t4_n[] = {1, 1, 1, 2, 2, 2};
    run_test("Symmetry: Target at start (Even)", t4_n, 6, 1, 0, 2);
    run_test("Symmetry: Target at end (Even)", t4_n, 6, 2, 3, 5);

    // 5. Minimal valid range: Two elements, one target
    int t5_n[] = {1, 2};
    run_test("Minimum: Start target", t5_n, 2, 1, 0, 0);
    run_test("Minimum: End target", t5_n, 2, 2, 1, 1);

    // 6. Out of Bounds: Target smaller than min or larger than max
    int t6_n[] = {10, 20, 30};
    run_test("OOB: Target too small", t6_n, 3, 5, -1, -1);
    run_test("OOB: Target too large", t6_n, 3, 40, -1, -1);

    // 7. Sparse duplicates: Multiple target clusters
    int t7_n[] = {1, 2, 2, 3, 4, 4, 4, 5, 6, 6};
    run_test("Sparse: Target in middle", t7_n, 10, 4, 4, 6);

    // 8. Single element mismatch
    int t8_n[] = {1};
    run_test("Single: Mismatch", t8_n, 1, 0, -1, -1);

    // 9. Gap Test: Target should be in a gap between two existing numbers
    int t9_n[] = {1, 2, 4, 5};
    run_test("Gap: Target in missing range", t9_n, 4, 3, -1, -1);

    return 0;
}
