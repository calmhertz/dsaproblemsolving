#include <stddef.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    int index;
    struct node* next;
} node;

void display(node* head){
    while (head) {
        head = head->next;
    }
}

node* add2ll(int value, size_t index, node* head){
    node* addition = (node*)malloc(sizeof(node));
    addition->value = value;
    addition->index = index;
    addition->next = NULL;
    if(!head){
        return addition;
    }
    node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = addition;
    return head;
}

int find(int key, node* head){
    if(!head){
        return -1;
    }
    while (head) {
        if(key == head->value){
            return head->index;
        }
        head = head->next;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    if(!nums){
        return NULL;
    }
    *returnSize = 2;
    node* llhead = NULL;
    int* ans = NULL;
    int key = 0, ind = 0;
    int targetZero = (target==0)?1:0;
    for(int i=0; i<numsSize; i++){
        if(targetZero){
            key = -1*nums[i];
        }
        else {
            key = target - nums[i];
        }
        ind = find(nums[i], llhead);
        if( ind >= 0){
            ans = (int*)malloc(*returnSize*sizeof(int));
            ans[0] = ind;
            ans[1] = i;
            return ans;
        }
        llhead = add2ll(key, i, llhead);
        display(llhead);
    }
    return ans;
}

// --------------------------------------------------------------------

//void runTest(int* nums, int size, int target) {
//    int returnSize = 0;
//    int* result = twoSum(nums, size, target, &returnSize);
//
//    printf("Array: ");
//    for (int i = 0; i < size; i++) {
//        printf("%d ", nums[i]);
//    }
//    printf("| Target: %d\n", target);
//
//    if (result != NULL && returnSize == 2) {
//        printf("Result: [%d, %d]\n", result[0], result[1]);
//        free(result);
//    } else {
//        printf("No valid pair found\n");
//    }
//    printf("-------------------------\n");
//}
//
//int main() {
//
//    int arr1[] = {3, 2, 4};
//    runTest(arr1, 3, 6);
//
//    int arr2[] = {3, 3};
//    runTest(arr2, 2, 6);
//
//    int arr3[] = {4, 1, 2, 3, 4};
//    runTest(arr3, 5, 8);
//
//    int arr4[] = {1000000000, 1000000000, -1000000000, -1000000000};
//    runTest(arr4, 4, 0);
//
//    int arr5[] = {INT_MAX, -1, 1, INT_MIN};
//    runTest(arr5, 4, INT_MAX - 1);
//
//    int arr6[] = {8, 7, 2, 5};
//    runTest(arr6, 4, 10);
//
//    int arr7[] = {2, 2, 2, 2, 2};
//    runTest(arr7, 5, 4);
//
//    int arr8[] = {-1000000000, 3, 1000000000, -3};
//    runTest(arr8, 4, 0);
//
//    int arr9[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    runTest(arr9, 10, 19);
//
//    int arr10[] = {1, 5, 3, 5};
//    runTest(arr10, 4, 10);
//
//    int arr11[] = {1000000000, -1000000000, 3, 3, 5, 5, -3, 7};
//    runTest(arr11, 8, 6);
//
//    int arr12[] = {0, 0, 0, 0, 1, -1};
//    runTest(arr12, 6, 0);
//
//    int arr13[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
//    runTest(arr13, 10, -19);
//
//    int arr14[] = {INT_MAX, INT_MAX - 1, -2, 3};
//    runTest(arr14, 4, INT_MAX - 3);
//
//    int arr15[] = {500000000, -500000000, 1, 2, 3, -1};
//    runTest(arr15, 6, 0);
//
//    return 0;
//}
