#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cassert>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* addToBst(TreeNode* root, vector<int>& nums, int l, int h) {
        if (l<0 || h>nums.size()-1 || l>h) {
            return nullptr;
        }

        int m = l + ((h-l)/2);
        if (root == nullptr) {
            root = new TreeNode(nums[m]);
        }

        if(l==m && m==h) {
            return new TreeNode(nums[m]);
        }

        root->left = addToBst(root->left, nums, l, m-1);
        root->right = addToBst(root->right, nums, m+1, h);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0;
        int h = static_cast<int>(nums.size()) - 1;

        return addToBst(nullptr, nums, l, h);
    }

};

bool isBSTUtil(TreeNode* node, long long minVal, long long maxVal) {
    if (!node) return true;
    if (node->val <= minVal || node->val >= maxVal) return false;
    return isBSTUtil(node->left, minVal, node->val) && isBSTUtil(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isBSTUtil(root, -2147483649LL, 2147483648LL);
}

int checkHeight(TreeNode* node, bool& balanced) {
    if (!node || !balanced) return 0;
    int leftHeight = checkHeight(node->left, balanced);
    int rightHeight = checkHeight(node->right, balanced);
    if (std::abs(leftHeight - rightHeight) > 1) {
        balanced = false;
    }
    return 1 + std::max(leftHeight, rightHeight);
}

bool isHeightBalanced(TreeNode* root) {
    bool balanced = true;
    checkHeight(root, balanced);
    return balanced;
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void runTest(vector<int>& nums) {
    Solution solver;
    TreeNode* root = solver.sortedArrayToBST(nums);
    
    if (nums.empty()) {
        assert(root == nullptr);
        return;
    }
    
    assert(isValidBST(root));
    assert(isHeightBalanced(root));
    
    freeTree(root);
}

int main() {
    vector<int> test1 = {-10, -3, 0, 5, 9};
    runTest(test1);

    vector<int> test2 = {1, 3};
    runTest(test2);

    vector<int> test3 = {0};
    runTest(test3);

    vector<int> test4 = {-5, -4, -3, -2, -1};
    runTest(test4);

    vector<int> test5 = {1, 2, 3, 4, 5, 6, 7};
    runTest(test5);

    vector<int> test6(10000);
    for (int i = 0; i < 10000; ++i) {
        test6[i] = i - 5000;
    }
    runTest(test6);

    std::cout << "All test cases passed successfully." << std::endl;
    return 0;
}
