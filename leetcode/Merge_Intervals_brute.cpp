class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int a=intervals[i][0],b=intervals[i][1];
            for(int j=i+1;j<n;j++){
                if(b>=intervals[j][0]){
                    b=max(b,intervals[j][1]);
                    i=j;
                }
                else{
                    break;
                }
            }
            ans.push_back({a,b});
        }
        return ans;
    }
};

//T.C
//Sorting: O(n log n)
//Merging: O(n)
//Total T.C = O(n log n)

//S.C = O(2n)= O(n)
