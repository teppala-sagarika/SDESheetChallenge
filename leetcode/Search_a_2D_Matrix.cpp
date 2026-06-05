// ────────────────────────────────────────────────────────────
// Problem : Search a 2D Matrix
// Platform: LeetCode
// URL     : https://leetcode.com/problems/search-a-2d-matrix/
// Language: cpp
// Date    : 6/5/2026, 2:29:41 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(log nm)
// Space Complexity: O(1)
// Notes           : arrays 3 - binary search for 2D as 1D
// ────────────────────────────────────────────────────────────

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //think 2D as 1D 
        //row = idx / col len
        //col = idx % col len
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0;
        int h=(n*m)-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(matrix[mid/m][mid%m]==target){
                return true;
            }
            else if(matrix[mid/m][mid%m]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return false;
    }
};