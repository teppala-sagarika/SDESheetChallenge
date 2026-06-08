//This works only if the array contains only 0s and positive no.s 

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n=nums.size();
        int len=0;
        int l=0,r=0;
        int s=nums[0];
        while(r<n){
            while(l<=r && s>k){
                s-=nums[l];
                l++;
            }
            if(s==k){
                len=max(len,r-l+1);
            }
            r++;
            if(r<n)
            s+=nums[r];
        }
        return len;
    }
};

//T.C = O(2n)
//S.C = O(1)
