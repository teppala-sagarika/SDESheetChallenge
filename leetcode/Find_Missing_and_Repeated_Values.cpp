// ────────────────────────────────────────────────────────────
// Problem : Find Missing and Repeated Values
// Platform: LeetCode
// URL     : https://leetcode.com/problems/find-missing-and-repeated-values/description/
// Language: cpp
// Date    : 6/4/2026, 4:38:15 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n^2)
// Space Complexity: O(1)
// Notes           : arrays2
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int sz=grid.size();//size
        long long n= 1LL*sz*sz;//tot ele
        long long es=n*(n+1)/2;//xpected sum
        long long ess=1LL*n*(n+1)*(2*n+1)/6; //xpected sq sum
        long long s=0;//actaul sum
        long long ss=0;//actual sq sum
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++){
                s+=grid[i][j];
                ss+=1LL*grid[i][j]*grid[i][j];
            }
        }
        //a^2 - b^2 = (a+b)(a-b)
        //sub = actual sq sum - xpected sq sum;
        //diffRM = actaul sum - xpected sum;
        long long sub = ss - ess;
        long long diffRM = s - es;
        long long sumRM = sub/diffRM;
        long long repeat = (sumRM+diffRM)/2;
        long long miss = sumRM-repeat;
        return {(int)repeat,(int)miss};
    }
};

//T.C = O(n^2) 
//S.C = O(1)