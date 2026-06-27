// ────────────────────────────────────────────────────────────
// Problem : Min Stack
// Platform: LeetCode
// URL     : https://leetcode.com/problems/min-stack/submissions/2047988178/
// Language: cpp
// Date    : 6/27/2026, 9:06:29 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(1)
// Space Complexity: O(n)
// ────────────────────────────────────────────────────────────

class MinStack {
public:
    long long mini = 1e9;
    stack<long long> st;

    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            mini = value;
        }
        else if(value < mini){
            st.push(2LL * value - mini);
            mini = value;
        }
        else{
            st.push(value);
        }
    }
    
    void pop() {
        if(st.top() < mini){
            mini = 2LL * mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < mini){
            return mini;
        }
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};