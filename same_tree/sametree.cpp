#include <iostream>
#include <vector>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<TreeNode*> stack1, stack2;

bool isSameTree(TreeNode* p, TreeNode* q) {
    if ( !p || !q ) {
        if (!p && !q) {
            return true;
        }
        return false;
    }
    if (p->val != q->val) {
        return false;
    }
    if (!isSameTree(p->left, q->left)) {
        return false;
    }
    if (!isSameTree(p->right, q->right)) {
        return false;
    }
    return true;
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* p1 = nullptr;
    TreeNode* q1 = nullptr;
    assert(isSameTree(p1, q1) == true);

    TreeNode* p2 = new TreeNode(5);
    TreeNode* q2 = nullptr;
    assert(isSameTree(p2, q2) == false);
    freeTree(p2);

    TreeNode* p3 = nullptr;
    TreeNode* q3 = new TreeNode(5);
    assert(isSameTree(p3, q3) == false);
    freeTree(q3);

    TreeNode* p4 = new TreeNode(42);
    TreeNode* q4 = new TreeNode(42);
    assert(isSameTree(p4, q4) == true);
    freeTree(p4);
    freeTree(q4);

    TreeNode* p5 = new TreeNode(42);
    TreeNode* q5 = new TreeNode(24);
    assert(isSameTree(p5, q5) == false);
    freeTree(p5);
    freeTree(q5);

    TreeNode* p6 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q6 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    assert(isSameTree(p6, q6) == true);
    freeTree(p6);
    freeTree(q6);

    TreeNode* p7 = new TreeNode(1, new TreeNode(2), nullptr);
    TreeNode* q7 = new TreeNode(1, nullptr, new TreeNode(2));
    assert(isSameTree(p7, q7) == false);
    freeTree(p7);
    freeTree(q7);

    TreeNode* p8 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q8 = new TreeNode(1, new TreeNode(2), new TreeNode(4));
    assert(isSameTree(p8, q8) == false);
    freeTree(p8);
    freeTree(q8);

    TreeNode* p9 = new TreeNode(-10000, new TreeNode(10000), new TreeNode(-10000));
    TreeNode* q9 = new TreeNode(-10000, new TreeNode(10000), new TreeNode(-10000));
    assert(isSameTree(p9, q9) == true);
    freeTree(p9);
    freeTree(q9);

    TreeNode* p10 = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3));
    TreeNode* q10 = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3));
    assert(isSameTree(p10, q10) == true);
    freeTree(p10);
    freeTree(q10);

    TreeNode* p11 = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3));
    TreeNode* q11 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)), new TreeNode(3));
    assert(isSameTree(p11, q11) == false);
    freeTree(p11);
    freeTree(q11);

    TreeNode* p12 = new TreeNode(0);
    TreeNode* currP = p12;
    for(int i = 0; i < 20; ++i) {
        currP->left = new TreeNode(i);
        currP = currP->left;
    }
    TreeNode* q12 = new TreeNode(0);
    TreeNode* currQ = q12;
    for(int i = 0; i < 20; ++i) {
        currQ->left = new TreeNode(i);
        currQ = currQ->left;
    }
    assert(isSameTree(p12, q12) == true);
    freeTree(p12);
    freeTree(q12);

    TreeNode* p13 = new TreeNode(0);
    currP = p13;
    for(int i = 0; i < 20; ++i) {
        currP->left = new TreeNode(i);
        currP = currP->left;
    }
    TreeNode* q13 = new TreeNode(0);
    currQ = q13;
    for(int i = 0; i < 19; ++i) {
        currQ->left = new TreeNode(i);
        currQ = currQ->left;
    }
    assert(isSameTree(p13, q13) == false);
    freeTree(p13);
    freeTree(q13);

    std::cout << "All robust test cases passed!" << std::endl;
    return 0;
}
