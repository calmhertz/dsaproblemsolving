#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid+1, k = 0;
    int temp[right - left + 1];

    while(i<=mid && j<=right) {
        if(arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }

    for(k = 0; k < (right - left + 1); k++){
        arr[left + k] = temp[k];
    }
}

void mergeSort(int arr[], int left, int right) {
    if(right <= left) {
        return;
    }

    int mid = left + ((right-left)/2);

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);

}

bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

void runTest(int* arr, int n, const char* testName) {
    printf("Running %s...\n", testName);
    int* copy = NULL;
    if (n > 0 && arr != NULL) {
        copy = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) copy[i] = arr[i];
    }
    
    if (n > 0 && copy != NULL) {
        mergeSort(copy, 0, n - 1);
    }
    
    if (isSorted(copy, n)) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }
    if (copy) free(copy);
}

int main() {
    runTest(NULL, 0, "Empty Array");

    int t2[] = {42};
    runTest(t2, 1, "Single Element");

    int t3[] = {5, 1};
    runTest(t3, 2, "Two Elements Unsorted");

    int t4[] = {1, 2};
    runTest(t4, 2, "Two Elements Sorted");

    int t5[] = {7, 7, 7, 7, 7};
    runTest(t5, 5, "All Identical Elements");

    int t6[] = {-3, 5, -1, 0, 9, -8, 5};
    runTest(t6, 7, "Mixed Negative and Positive Numbers");

    int t7[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    runTest(t7, 10, "Already Sorted");

    int t8[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    runTest(t8, 10, "Reverse Sorted");

    int t9[] = {4, 2, 4, 3, 1, 2, 1, 3};
    runTest(t9, 8, "Many Duplicates");

    int t10[10000];
    for (int i = 0; i < 10000; i++) {
        t10[i] = 10000 - i;
    }
    runTest(t10, 10000, "Large Reverse Sorted Array");

    return 0;
}
