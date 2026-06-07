class Solution {
public:
    bool ls(vector<int>& nums,int n,int k){
        for(int i=0;i<n;i++){
            if(nums[i]==k) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int l=1;
        for(int i=0;i<n;i++){
            int x=nums[i];
            int c=1;
            while(ls(nums,n,x+1)==true){
                x=x+1;
                c++;
            }
            l=max(l,c);
        }
        return l;
    }
};

//T.C = O(n^2)
//S.C = O(1)
