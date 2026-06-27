// ────────────────────────────────────────────────────────────
// Problem : Sliding Window Maximum
// Platform: LeetCode
// URL     : https://leetcode.com/problems/sliding-window-maximum/
// Language: cpp
// Date    : 6/27/2026, 9:01:59 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(N)
// Space Complexity: O(K)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<n;i++){
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while(!dq.empty() &&  nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if (i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};