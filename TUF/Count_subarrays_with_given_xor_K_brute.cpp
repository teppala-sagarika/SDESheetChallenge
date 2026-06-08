class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            int x=0;
            for(int j=i;j<n;j++){
                x^=nums[j];
                if(x==k){
                    c++;
                }
            }
        }
        return c;
    }
};

//T.C = O(n^2)
//S.C = O(1)
