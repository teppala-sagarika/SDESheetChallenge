class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n=nums.size();
        int l=0;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=nums[j];
                if(s==k){
                    l=max(l,j-i+1);
                }
            }
        }
        return l;
    }
};


//T.C = O(n^2)
//S.C = O(1)
