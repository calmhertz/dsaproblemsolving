#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mapp;
        mapp.insert({target-nums[0], 0});
        for(int i=1; i<nums.size(); i++){
            if(mapp.find(nums[i]) != mapp.end()){
                return {mapp[nums[i]], i};
            }
            else{
                mapp.insert({target-nums[i], i});
            }
        }
        return {};
    }
};

int main() {
    Solution sol;

    // List of challenging test cases
    vector<pair<vector<int>, int>> testCases = {
        {{2, 7, 11, 15}, 9},                       // Normal case
        {{-3, 4, 3, 90}, 0},                        // Negative numbers
        {{3, 3}, 6},                                // Duplicates
        {{1000000000, 2000000000, -1500000000}, 500000000}, // Large numbers
        {{1, 2, 3, 4}, 10},                         // No valid pair
        {{-10, -20, -30, -40, -50}, -30},           // All negative numbers
        {{0, 0, 0, 0}, 0},                           // All zeros
        {{1, 2, 3, 4, 2, 3}, 5},                     // Multiple valid pairs
        {{INT_MAX, INT_MIN, -1, 1}, 0},             // Extreme integer values
        {vector<int>(10000, 1), 2}                  // Very large array with duplicates
    };

    // Descriptions
    vector<string> descriptions = {
        "Normal case",
        "Negative numbers",
        "Duplicates",
        "Large numbers",
        "No valid pair",
        "All negative numbers",
        "All zeros",
        "Multiple valid pairs",
        "Extreme integer values",
        "Very large array with duplicates"
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto& nums = testCases[i].first; // non-const to match twoSum signature
        int target = testCases[i].second;

        cout << "===== Test Case " << i + 1 << " (" << descriptions[i] << ") =====" << endl;
        cout << "Input Array: [ ";
        for (size_t j = 0; j < min(nums.size(), size_t(20)); ++j) // print first 20 elements only if very large
            cout << nums[j] << " ";
        if (nums.size() > 20) cout << "..."; 
        cout << "]" << endl;
        cout << "Target: " << target << endl;

        vector<int> result = sol.twoSum(nums, target);

        cout << "Result Indices: [ ";
        for (int idx : result) cout << idx << " ";
        cout << "]" << endl << endl;
    }

    return 0;
}
