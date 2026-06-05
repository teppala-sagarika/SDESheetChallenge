class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(nums[j]==nums[i]){
                    c++;
                }
                if(c>n/2){
                    return i;
                }
            }
        }
        return -1;
    }
};

//T.C = O(n^2)
//S.C = O(1)
