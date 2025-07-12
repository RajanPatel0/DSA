#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        for (int num : s1) {
            if (s2.find(num) == s2.end()) {
                ans[0].push_back(num);
            }
        }

        for (int num : s2) {
            if (s1.find(num) == s1.end()) {
                ans[1].push_back(num);
            }
        }

        return ans;
    }
};

// 🔍 Helper function to print result
void printResult(vector<vector<int>> result) {
    for (auto list : result) {
        cout << "  [ ";
        for (int num : list) {
            cout << num << " ";
        }
        cout << "]\n";
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    Solution sol;
    vector<vector<int>> result = sol.findDifference(nums1, nums2);

    cout << "Difference of arrays:\n";
    printResult(result);

    return 0;
}
