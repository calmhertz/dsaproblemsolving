#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeElement(int* nums, int numsSize, int val);

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void run_test(const char* testName, int* nums, int numsSize, int val, int* expectedNums, int expectedK) {
    int* numsCopy = NULL;
    if (numsSize > 0) {
        numsCopy = (int*)malloc(numsSize * sizeof(int));
        memcpy(numsCopy, nums, numsSize * sizeof(int));
    }

    int k = removeElement(numsCopy, numsSize, val);

    if (k != expectedK) {
        printf("[FAILED] %s: Expected k=%d, got k=%d\n", testName, expectedK, k);
        return;
    }

    if (k > 0) {
        qsort(numsCopy, k, sizeof(int), compare);
        
        int* expectedCopy = (int*)malloc(expectedK * sizeof(int));
        memcpy(expectedCopy, expectedNums, expectedK * sizeof(int));
        qsort(expectedCopy, expectedK, sizeof(int), compare);

        for (int i = 0; i < k; i++) {
            if (numsCopy[i] != expectedCopy[i]) {
                printf("[FAILED] %s: Array mismatch at index %d. Expected %d, got %d\n", 
                       testName, i, expectedCopy[i], numsCopy[i]);
                return;
            }
        }
    }

    printf("[PASSED] %s\n", testName);
}

int main() {
    {
        int nums[] = {3, 2, 2, 3};
        int expected[] = {2, 2};
        run_test("Standard Case (Small)", nums, 4, 3, expected, 2);
    }

    {
        int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
        int expected[] = {0, 1, 3, 0, 4};
        run_test("Standard Case (Medium)", nums, 8, 2, expected, 5);
    }

    {
        run_test("Edge: Empty Array", NULL, 0, 0, NULL, 0);
    }

    {
        int nums[] = {1};
        int expected[] = {};
        run_test("Edge: Single Element Match", nums, 1, 1, expected, 0);
    }

    {
        int nums[] = {4, 4, 4, 4};
        int expected[] = {};
        run_test("Edge: All Elements Match", nums, 4, 4, expected, 0);
    }

    {
        int nums[] = {1, 2, 3, 4, 5};
        int expected[] = {1, 2, 3, 4, 5};
        run_test("Edge: No Elements Match", nums, 5, 6, expected, 5);
    }

    {
        int nums[100];
        int expected[50];
        for (int i = 0; i < 100; i++) nums[i] = (i % 2 == 0) ? 50 : 100;
        for (int i = 0; i < 50; i++) expected[i] = 100;
        run_test("Robust: Max Constraints (100 elements)", nums, 100, 50, expected, 50);
    }

    {
        int nums[] = {0, 0, 0, 1, 1, 1};
        int expected[] = {1, 1, 1};
        run_test("Robust: Multiple Leading Targets", nums, 6, 0, expected, 3);
    }

    return 0;
}


int removeElement(int* nums, int numsSize, int val) {
    if(!nums){
        return 0;
    }
    else if(numsSize == 0) {
        return numsSize;
    }
    else if(numsSize == 1){ 
        if(nums[0]==val) { return 0; }
        else{ return 1;}
    }
    int j = numsSize-1;
    for(int i=0; j>=i; i++){
        if(nums[i] == val){
            while(nums[j]==val && j>i){ j--; }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j--;
        }
    }
    return j+1;
}
