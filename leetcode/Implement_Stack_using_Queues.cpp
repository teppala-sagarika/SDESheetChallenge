// ────────────────────────────────────────────────────────────
// Problem : Implement Stack using Queues
// Platform: LeetCode
// URL     : https://leetcode.com/problems/implement-stack-using-queues/submissions/2044742875/
// Language: cpp
// Date    : 6/24/2026, 9:25:48 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : push = O(N) , others = O(1)
// Space Complexity: O(N)
// ────────────────────────────────────────────────────────────

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int n=q.size();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */