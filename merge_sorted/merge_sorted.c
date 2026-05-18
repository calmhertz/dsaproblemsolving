#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

void merge(int* nums1, int nums1size, int m, int* nums2, int nums2size, int n) {
    int i = m-1, j = n-1, k = nums1size - 1; 
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[k--] = nums1[i--];
        }
        else {
            nums1[k--] = nums2[j--];
        }
    }
    while (i >= 0) {
        nums1[k--] = nums1[i--];
    }
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

bool compareArrays(int* arr1, int* arr2, int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

int main() {
    {
        int nums1[6] = {1, 2, 3, 0, 0, 0};
        int nums2[3] = {2, 5, 6};
        int expected[6] = {1, 2, 2, 3, 5, 6};
        merge(nums1, 6, 3, nums2, 3, 3);
        if (!compareArrays(nums1, expected, 6)) return 1;
    }

    {
        int nums1[1] = {1};
        int nums2[1] = {0};
        int expected[1] = {1};
        merge(nums1, 1, 1, nums2, 0, 0);
        if (!compareArrays(nums1, expected, 1)) return 1;
    }

    {
        int nums1[1] = {0};
        int nums2[1] = {1};
        int expected[1] = {1};
        merge(nums1, 1, 0, nums2, 1, 1);
        if (!compareArrays(nums1, expected, 1)) return 1;
    }

    {
        int nums1[5] = {-10, -5, 0, 0, 0};
        int nums2[3] = {-7, -3, 2};
        int expected[5] = {-10, -7, -5, -3, 2};
        merge(nums1, 5, 2, nums2, 3, 3);
        if (!compareArrays(nums1, expected, 5)) return 1;
    }

    {
        int nums1[4] = {4, 5, 0, 0};
        int nums2[2] = {1, 2};
        int expected[4] = {1, 2, 4, 5};
        merge(nums1, 4, 2, nums2, 2, 2);
        if (!compareArrays(nums1, expected, 4)) return 1;
    }

    {
        int nums1[4] = {1, 2, 0, 0};
        int nums2[2] = {4, 5};
        int expected[4] = {1, 2, 4, 5};
        merge(nums1, 4, 2, nums2, 2, 2);
        if (!compareArrays(nums1, expected, 4)) return 1;
    }

    {
        int nums1[6] = {2, 2, 2, 0, 0, 0};
        int nums2[3] = {2, 2, 2};
        int expected[6] = {2, 2, 2, 2, 2, 2};
        merge(nums1, 6, 3, nums2, 3, 3);
        if (!compareArrays(nums1, expected, 6)) return 1;
    }

    printf("All tests passed successfully.\n");
    return 0;
}
