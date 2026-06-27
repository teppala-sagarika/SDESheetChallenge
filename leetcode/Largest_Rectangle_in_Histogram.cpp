// ────────────────────────────────────────────────────────────
// Problem : Largest Rectangle in Histogram
// Platform: LeetCode
// URL     : https://leetcode.com/problems/largest-rectangle-in-histogram/
// Language: cpp
// Date    : 6/27/2026, 8:58:34 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(N)
// Space Complexity: O(N)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxAr=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int element=st.top();
                st.pop();
                int nse=i;
                int pse=(st.empty())?-1:st.top();
                maxAr=max(maxAr,heights[element]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int element=st.top();
            st.pop();
            int pse=(st.empty())?-1:st.top();
            maxAr=max(maxAr,heights[element]*(nse-pse-1));
        }
        return maxAr;
    }
};