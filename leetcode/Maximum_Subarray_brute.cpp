class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int k=i;k<=j;k++)
                sum+=nums[k];
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};

//T.C = O(n^3)
//S.C = O(1)
