#include <iostream>
#include <system_error>
#include <vector>
#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {        
        if(head == nullptr){
            return nullptr;
        }
        else if(head->next == nullptr){
            return head;
        }

        ListNode* current = head;
        ListNode* next = head->next;

        while (next != nullptr) {
            if(current->val == next->val) {
                current->next = next->next;
                delete next;
                next = current->next;
            }
            else {
                current = next;
                next = next->next;
            }
        }

        return head;
    }
};

ListNode* createList(const std::vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

std::vector<int> listToVector(ListNode* head) {
    std::vector<int> vals;
    ListNode* curr = head;
    while (curr != nullptr) {
        vals.push_back(curr->val);
        curr = curr->next;
    }
    return vals;
}

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void runTest(const std::vector<int>& input, const std::vector<int>& expected) {
    ListNode* head = createList(input);
    Solution solver;
    ListNode* result = solver.deleteDuplicates(head);
    std::vector<int> output = listToVector(result);
    assert(output == expected);
    freeList(result);
}

int main() {
    runTest({}, {});
    runTest({5}, {5});
    runTest({1, 1, 2}, {1, 2});
    runTest({1, 1, 2, 3, 3}, {1, 2, 3});
    runTest({1, 1, 1, 1, 1}, {1});
    runTest({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});
    runTest({-100, -100, 0, 0, 100, 100}, {-100, 0, 100});
    runTest({-50, -50, -50, 0, 0, 50, 50}, {-50, 0, 50});
    
    std::vector<int> largeInput;
    std::vector<int> largeExpected;
    for (int i = -100; i <= 100; ++i) {
        largeInput.push_back(i);
        largeInput.push_back(i);
        largeExpected.push_back(i);
    }
    runTest(largeInput, largeExpected);

    std::cout << "All test cases passed successfully!" << std::endl;
    return 0;
}
