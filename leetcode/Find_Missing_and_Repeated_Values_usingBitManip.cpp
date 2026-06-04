class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int x=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                x^=grid[i][j];
            }
        }
        for(int i=1;i<=n*n;i++){
            x^=i;
        }
        int bitNo=0;
        while(true){
            if(x & (1<<bitNo)){
                break;
            }
            bitNo++;
        }
        int zero=0,one=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] & (1<<bitNo)){
                    one^=grid[i][j];
                }
                else{
                    zero^=grid[i][j];
                }
            }
        }
        for(int i=1;i<=n*n;i++){
        if(i & (1<<bitNo)){
        one ^= i;
        }
        else{
        zero ^= i;
        }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==zero){
                    c++;
                }
            }
        }
        if(c==2){
            return {zero,one};
        }
        return {one,zero};
    }
};

//T.C = O(n^2)
//S.C = O(1)
