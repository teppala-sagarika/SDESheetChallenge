class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n=M.size();
        for(int i=0;i<n;i++){
            bool f=true;
            for(int j=0;j<n;j++){
                if(M[i][j]==1){
                    f=false;
                    break;
                }
            }
            if(f){
                return i;
            }
        }
        return -1;
    }
};

//TC = O(n^2)
//SC = O(1)
