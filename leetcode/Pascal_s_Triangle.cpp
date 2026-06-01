// ────────────────────────────────────────────────────────────
// Problem : Pascal's Triangle
// Platform: LeetCode
// URL     : https://leetcode.com/problems/pascals-triangle/submissions/2018789777/
// Language: cpp
// Date    : 6/1/2026, 11:57:49 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n^2)
// Space Complexity: O(n^2)
// Notes           : Arrays
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri;
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,1);
            for(int j=1;j<i;j++){//exclude start and end as they be 1 anyways
                row[j]=tri[i-1][j-1]+tri[i-1][j];
            }
            tri.push_back(row);
        }
        return tri;
    }
};