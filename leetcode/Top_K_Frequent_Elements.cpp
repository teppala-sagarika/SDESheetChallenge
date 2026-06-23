// ────────────────────────────────────────────────────────────
// Problem : Top K Frequent Elements
// Platform: LeetCode
// URL     : https://leetcode.com/problems/top-k-frequent-elements/submissions/2043528335/
// Language: cpp
// Date    : 6/23/2026, 9:24:30 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n + m log k)
// Space Complexity: O(m+k)
// Notes           : m = no. of unique elements (HEAPS)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto &x:nums){
            mp[x]++;
        }
        //min heap
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > pq;
        for(auto p:mp){
            pq.push({p.second,p.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};