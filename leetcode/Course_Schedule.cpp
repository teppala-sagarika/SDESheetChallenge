// ────────────────────────────────────────────────────────────
// Problem : Course Schedule
// Platform: LeetCode
// URL     : https://leetcode.com/problems/course-schedule/submissions/2072109879/
// Language: cpp
// Date    : 7/18/2026, 4:16:26 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(V + E)
// Space Complexity: O(V + E)
// Notes           : using topological sort - BFS (only applicable for DAGs)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorder(numCourses,0);
        vector<vector<int>> adjlst(numCourses);
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            inorder[a]++;
            adjlst[b].push_back(a);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        vector<int> topoSort;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topoSort.push_back(node);
            for(int it:adjlst[node]){
                inorder[it]--;
                if(inorder[it]==0){
                    q.push(it);
                }
            }
        }
        if(topoSort.size()==numCourses){
            //no cycle - DAG 
            return true;
        }
        return false;
    }
};