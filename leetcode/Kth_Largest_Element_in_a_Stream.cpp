// ────────────────────────────────────────────────────────────
// Problem : Kth Largest Element in a Stream
// Platform: LeetCode
// URL     : https://leetcode.com/problems/kth-largest-element-in-a-stream/submissions/2069317608/
// Language: cpp
// Date    : 7/16/2026, 10:01:46 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(??)
// Space Complexity: O(??)
// ────────────────────────────────────────────────────────────

class KthLargest {
public:
priority_queue<int,vector<int>,greater<int>> pq;//min heap
int k;
    KthLargest(int k, vector<int>& nums) {
      this->k=k;
      for(int x:nums){
        pq.push(x);
        if(pq.size()>k){
            pq.pop();
        }
      }  
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */