//TUF
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n=nums.size();
        vector<int> hash(n+1,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        int repeat=-1,miss=-1;
        for(int i=1;i<=n;i++){
            if(hash[i]==2) repeat=i;
            else if(hash[i]==0) miss=i;
            if(repeat!=-1 && miss!=-1){
                break;
            }
        }
        return {repeat,miss};
    }
};
//T.C = O(2n)
//S.C = O(n)
