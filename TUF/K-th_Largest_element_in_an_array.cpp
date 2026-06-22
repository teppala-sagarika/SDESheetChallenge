class Solution {
public:
    int kthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

//TC = O(n log k)
//SC = O(k)
