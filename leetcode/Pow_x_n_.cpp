// ────────────────────────────────────────────────────────────
// Problem : Pow(x, n)
// Platform: LeetCode
// URL     : https://leetcode.com/problems/powx-n/description/
// Language: cpp
// Date    : 6/5/2026, 3:06:43 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(log n)
// Space Complexity: O(1)
// Notes           : arrays 3
// ────────────────────────────────────────────────────────────

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long pow=n;
        if(pow<0) pow*=-1;
        while(pow){
            if(pow%2==0){
                x=x*x;
                pow/=2;
            }
            else{
                ans*=x;
                pow-=1;
            }
        }
        if(n<0) ans=1.0/ans;
        return ans;
    }
};