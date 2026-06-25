// ────────────────────────────────────────────────────────────
// Problem : Next Greater Element I
// Platform: LeetCode
// URL     : https://leetcode.com/problems/next-greater-element-i/submissions/2046069694/
// Language: cpp
// Date    : 6/25/2026, 11:10:32 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n1 + n2)
// Space Complexity: O(n2)
// Notes           : stacks
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,int> mp;
        stack<int> st;
        st.push(nums2[0]);
        for(int i=1;i<n2;i++){
            while(!st.empty() && st.top()<nums2[i]){
                mp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<n1;i++){
            if(mp.count(nums1[i])){
                ans.push_back(mp[nums1[i]]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};