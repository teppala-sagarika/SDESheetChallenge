// ────────────────────────────────────────────────────────────
// Problem : Course Schedule
// Platform: LeetCode
// URL     : https://leetcode.com/problems/course-schedule/submissions/2071888512/
// Language: cpp
// Date    : 7/18/2026, 12:22:47 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(E) + O(V + E)
// Space Complexity: O(V + E)
// Notes           : detect cycle using dfs (2 visited arrays)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    bool dfsCheckCycle(int i,vector<vector<int>> &adjlst,vector<int> &vis,vector<int>& dfsVis){
        vis[i]=1;
        dfsVis[i]=1;
        for(int it:adjlst[i]){
            if(!vis[it]){
                if(dfsCheckCycle(it,adjlst,vis,dfsVis)==true){
                    return true;
                }
            }else{
                if(dfsVis[it]){
                    return true;
                }
            }
        }
        dfsVis[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0),dfsVis(numCourses,0);
        vector<vector<int>> adjlst(numCourses);
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adjlst[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfsCheckCycle(i,adjlst,vis,dfsVis)==true){
                    return false;
                }
            }
        }
        return true;
    }
};