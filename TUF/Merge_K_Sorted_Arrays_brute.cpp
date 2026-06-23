class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                pq.push(arr[i][j]);
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

//TC = O(k^2 log(k^2))
//SC = O(k^2)
