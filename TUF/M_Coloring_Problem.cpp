class Solution{
public:
    bool isSafe(int i,int color,vector<int>& col,vector<vector<int> >& adj,int n){
        for(auto &nei:adj[i]){
            if(col[nei]==color){
                return false;
            }
        }
        return true;
    }
    bool solve(int i,vector<int>& col,vector<vector<int> >& adj, int m, int n){
        if(i==n){//all nodes covered
            return true;
        }
        for(int color=1;color<=m;color++){
            if(isSafe(i,color,col,adj,n)){
                col[i]=color;
                if(solve(i+1,col,adj,m,n)) return true;
                col[i]=0;
            }
        }
        return false;
    }
    bool graphColoring(vector<vector<int> >& edges, int m, int n) {
        vector<int> col(n,0);//initially all are not colored 
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(solve(0,col,adj,m,n)){
            return true;
        }
        return false;
    }
};

//T.C = O(m^n×(V+E))
//S.C = O(V+E)
