// ────────────────────────────────────────────────────────────
// Problem : Online Stock Span
// Platform: LeetCode
// URL     : https://leetcode.com/problems/online-stock-span/submissions/2048808482/
// Language: cpp
// Date    : 6/28/2026, 3:28:56 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(n)
// ────────────────────────────────────────────────────────────

class StockSpanner {
public:
    stack<pair<int,int>> st; // price , span
    StockSpanner() {
    }
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};