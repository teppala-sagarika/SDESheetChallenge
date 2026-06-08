class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n=nums.size();
        int c=0;
        int xr=0;
        unordered_map<int,int> mp;
        mp[xr]++;
        for(int i=0;i<n;i++){
            xr^=nums[i];
            int x=xr^k;
            c+=mp[x];
            mp[xr]++;
        }
        return c;
    }
};

//T.C = O(n)
//S.C = O(n)
