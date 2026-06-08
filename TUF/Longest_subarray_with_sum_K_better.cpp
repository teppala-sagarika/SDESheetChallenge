class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n=nums.size();
        int l=0;
        unordered_map<int,int> prefMp;
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(prefMp.find(s)==prefMp.end())
            prefMp[s]=i+1;
            if(s==k){
                l=max(l,i+1);
            }
            int rem=s-k;
            if(prefMp.find(rem)!=prefMp.end()){
                l=max(l,i+1-prefMp[rem]);
            }
        }
        return l;
    }
};

//T.C = O(n)
//S.C = O(n)
