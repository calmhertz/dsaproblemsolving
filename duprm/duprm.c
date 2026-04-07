#include <stdio.h>
#include <stdbool.h>

int removeDuplicates(int* nums, int numsSize) {
    if(!nums){
        return 0;
    }
    int i=0, j=1, last=nums[0];
    while (i<numsSize && j<numsSize) { 
        if(nums[j]==last){
            j++;
        }
        else {
            nums[++i] = nums[j];
            last = nums[j];
            j++;
        }
    }
    return i+1;
}

void verify(int id, int* nums, int size, int* expected, int expectedK) {
    int k = removeDuplicates(nums, size);
    bool match = (k == expectedK);
    for (int i = 0; i < k && match; i++) {
        if (nums[i] != expected[i]) match = false;
    }
    if (match) printf("Test %d Passed\n", id);
    else printf("Test %d Failed (Expected k=%d, got %d)\n", id, expectedK, k);
}

int main() {
    int n1[] = {1, 1, 2};
    int e1[] = {1, 2};
    verify(1, n1, 3, e1, 2);

    int n2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int e2[] = {0, 1, 2, 3, 4};
    verify(2, n2, 10, e2, 5);

    int n3[] = {1};
    int e3[] = {1};
    verify(3, n3, 1, e3, 1);

    int n4[] = {1, 1, 1, 1, 1};
    int e4[] = {1};
    verify(4, n4, 5, e4, 1);

    int n5[] = {1, 2, 3, 4, 5};
    int e5[] = {1, 2, 3, 4, 5};
    verify(5, n5, 5, e5, 5);

    int n6[] = {-100, -100, -50, -50, 0, 50, 100, 100};
    int e6[] = {-100, -50, 0, 50, 100};
    verify(6, n6, 8, e6, 5);

    int n7[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int e7[] = {1, 2, 3, 4, 5};
    verify(7, n7, 10, e7, 5);

    return 0;
}
