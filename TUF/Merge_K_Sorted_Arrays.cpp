class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        vector<int> ans;

        // push first element of every array
        for(int i = 0; i < k; i++) {
            pq.push({arr[i][0], {i, 0}});
        }

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int val = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            ans.push_back(val);

            // push next element from same array
            if(col + 1 < k) {
                pq.push({arr[row][col+1], {row, col+1}});
            }
        }

        return ans;
    }
};

//TC = O(k² log k)
//SC = O(k)
