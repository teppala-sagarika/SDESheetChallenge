class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        int a = 0;
        int b = n - 1;
        while(a < b){
            if(M[a][b] == 1){
                a++;
            }
            else{
                b--;
            }
        }
        int candidate = a;
        for(int i = 0; i < n; i++){
            if(M[candidate][i] == 1){
                return -1;
            }
        }
        for(int i = 0; i < n; i++){
            if(i != candidate && M[i][candidate] == 0){
                return -1;
            }
        }
        return candidate;
    }
};
//TC = O(n)
//SC = O(1)
