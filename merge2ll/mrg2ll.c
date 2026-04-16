#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(!list1){
        return list2;
    }
    else if(!list2){
        return list1;
    }
    struct ListNode* mergedList;
    if(list1->val < list2->val){
        mergedList = list1;
        list1 = list1->next;
    }
    else{
        mergedList = list2;
        list2 = list2->next;
    }
    struct ListNode* temp = mergedList;
    while(list1 && list2){ 
        if(list1->val <= list2->val){
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }
    }
    if(list1){
        temp->next = list1;
    }
    else if(list2){
        temp->next = list2;
    }
    temp = mergedList;
    return mergedList;
}

struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr = curr->next;
        curr->val = arr[i];
        curr->next = NULL;
    }
    return head;
}

bool compareLists(struct ListNode* l1, struct ListNode* l2) {
    while (l1 && l2) {
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == NULL && l2 == NULL;
}

void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct TestCase {
        int arr1[100];
        int size1;
        int arr2[100];
        int size2;
        int expected[200];
        int expectedSize;
    };

    struct TestCase tests[] = {
        {{1, 2, 4}, 3, {1, 3, 4}, 3, {1, 1, 2, 3, 4, 4}, 6},
        {{}, 0, {}, 0, {}, 0},
        {{}, 0, {0}, 1, {0}, 1},
        {{1}, 1, {}, 0, {1}, 1},
        {{1, 2, 3}, 3, {4, 5, 6}, 3, {1, 2, 3, 4, 5, 6}, 6},
        {{5, 6, 7}, 3, {1, 2, 3}, 3, {1, 2, 3, 5, 6, 7}, 6},
        {{1, 1, 1}, 3, {1, 1, 1}, 3, {1, 1, 1, 1, 1, 1}, 6},
        {{-100, -50, 0}, 3, {-75, 25, 100}, 3, {-100, -75, -50, 0, 25, 100}, 6},
        {{1, 10, 20}, 3, {2, 3, 4, 5, 6}, 5, {1, 2, 3, 4, 5, 6, 10, 20}, 8}
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < numTests; i++) {
        struct ListNode* l1 = createList(tests[i].arr1, tests[i].size1);
        struct ListNode* l2 = createList(tests[i].arr2, tests[i].size2);
        struct ListNode* expected = createList(tests[i].expected, tests[i].expectedSize);

        struct ListNode* result = mergeTwoLists(l1, l2);

        if (!compareLists(result, expected)) {
            printf("Test Case %d Failed\n", i + 1);
            return 1;
        }

        freeList(result);
        freeList(expected);
    }

    printf("All robust test cases passed successfully\n");
    return 0;
}
