class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n),ryt(n);
        int l=0,r=0;
        for(int i=0;i<n;i++){
            l=left[i]=max(l,height[i]);
            r=ryt[n-i-1]=max(r,height[n-1-i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int mini=min(left[i],ryt[i]);
            ans+=mini-height[i];
        }
        return ans;
    }
};

//T.C = O(n)
//S.C = O(n)
