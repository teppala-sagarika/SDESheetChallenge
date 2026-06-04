//TUF
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n=nums.size();
        int repeat,miss;
        for(int i=1;i<=n;i++){
        int c=0;
          for(int j=0;j<n;j++){
          if(i==nums[j]){
             c++;
          }
          }
          if(c==2){
            repeat=i;
          }
          else if(c==0){
            miss=i;
          }
        }
      return {repeat,miss};
    }
};

//T.C = O(n^2)
//S.C = O(1)
