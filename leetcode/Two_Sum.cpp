// ────────────────────────────────────────────────────────────
// Problem : Two Sum
// Platform: LeetCode
// URL     : https://leetcode.com/problems/two-sum/submissions/2024828002/
// Language: cpp
// Date    : 6/7/2026, 7:41:41 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n log n)
// Space Complexity: O(n)
// Notes           : 2 pointer
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i}); // {value, index}
        }

        sort(arr.begin(), arr.end());

        int l = 0;
        int r = n - 1;

        while (l < r) {
            int sum = arr[l].first + arr[r].first;

            if (sum == target) {
                return {arr[l].second, arr[r].second};
            }
            else if (sum < target) {
                l++;
            }
            else {
                r--;
            }
        }

        return {};
    }
};