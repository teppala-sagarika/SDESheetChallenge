class Solution {  
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[2] > b[2];
    }
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        int n = Jobs.size();
        sort(Jobs.begin(), Jobs.end(), comp);
        int d = 0;
        for(int i = 0; i < n; i++){
           d = max(d, Jobs[i][1]);
        }
        vector<int> deadlines(d+1, -1);
        int c = 0;
        int prof = 0;
        for(int i = 0; i < n; i++){
            for(int j = Jobs[i][1]; j > 0; j--){
                if(deadlines[j] == -1){
                    deadlines[j] = Jobs[i][0];
                    c++;
                    prof += Jobs[i][2];
                    break;
                }
            }
        }
        return {c, prof};
    } 
};

//T.C = O(n^2)
//S.C = O(n)
