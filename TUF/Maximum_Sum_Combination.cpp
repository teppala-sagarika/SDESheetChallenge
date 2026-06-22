class Solution {
public:
    vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end(), greater<int>());
        sort(nums2.begin(), nums2.end(), greater<int>());
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> visited;
        pq.push({nums1[0] + nums2[0], {0,0}});
        visited.insert({0,0});
        vector<int> ans;
        while(k-- && !pq.empty()){
            auto top = pq.top();
            pq.pop();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            ans.push_back(sum);
            // move in nums1
            if(i+1 < n && visited.find({i+1,j}) == visited.end()){
                pq.push({nums1[i+1] + nums2[j], {i+1,j}});
                visited.insert({i+1,j});
            }
            // move in nums2
            if(j+1 < n && visited.find({i,j+1}) == visited.end()){
                pq.push({nums1[i] + nums2[j+1], {i,j+1}});
                visited.insert({i,j+1});
            }
        }
        return ans;
    }
};

//TC = O(n log n + k log k)
//SC = O(k)
