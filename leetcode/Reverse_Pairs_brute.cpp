class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((long long)nums[i] > 2LL * nums[j]){
                    c++;
                }
            }
        }
        return c;
    }
};
//T.C = O(n^2)
//S.C = O(1)
