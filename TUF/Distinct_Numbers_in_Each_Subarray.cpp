class Solution {
public:
 vector<int> distinctNumbers(vector<int>& nums, int k) {
     unordered_map<int,int> mp;
     vector<int> ans;
     for(int i=0;i<k;i++){
        mp[nums[i]]++;
     }
     ans.push_back(mp.size()); 
     int n=nums.size();
     //sliding window
     for(int i=k;i<n;i++){
        mp[nums[i-k]]--;//remove left element
        if(mp[nums[i-k]]==0){
            //if freq==0 then remove it from the map 
            mp.erase(nums[i-k]);
        }
        mp[nums[i]]++;
        ans.push_back(mp.size());
     }
     return ans;
 }
};
//T.C = O(n)
//S.C = O(n)
