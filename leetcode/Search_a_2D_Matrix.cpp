// ────────────────────────────────────────────────────────────
// Problem : Search a 2D Matrix
// Platform: LeetCode
// URL     : https://leetcode.com/problems/search-a-2d-matrix/submissions/2022941453/
// Language: cpp
// Date    : 6/5/2026, 11:29:01 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n+m)
// Space Complexity: O(1)
// Notes           : Arrays 3
// ────────────────────────────────────────────────────────────

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //start ptr with 1st row last col
        //move ptr left if target is smaller 
        //move ptr down if target is larger
        //stop if out of bound = not found
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0,j=m-1;
        while(i<n && j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target){
                j--;//left
            }
            else{
                i++;//down
            }
        }
        return false;
    }
};