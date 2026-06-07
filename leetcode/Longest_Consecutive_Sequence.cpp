// ────────────────────────────────────────────────────────────
// Problem : Longest Consecutive Sequence
// Platform: LeetCode
// URL     : https://leetcode.com/problems/longest-consecutive-sequence/submissions/2025638997/
// Language: cpp
// Date    : 6/7/2026, 11:52:17 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(3n)
// Space Complexity: O(n)
// Notes           : using a set
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;

        int longest = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int c=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    c++;
                }
                longest=max(longest,c);
            }
        }
        return longest;
    }
};

