// ────────────────────────────────────────────────────────────
// Problem : is-graph-bipartite
// Platform: LeetCode
// URL     : https://leetcode.com/problems/is-graph-bipartite/
// Language: C++
// Date    : 7/23/2026, 10:31:54 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(V + E)
// Space Complexity: O(V)
// Notes           : dfs
// ────────────────────────────────────────────────────────────

class Solution {
private:
    bool dfs(int i,int col,vector<int>& color,vector<vector<int>>& graph){
        color[i]=col;
        for(auto it:graph[i]){
            if(color[it]==-1){
                if(!dfs(it,!col,color,graph)) return false;
            }else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,0,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};