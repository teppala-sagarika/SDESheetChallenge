class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];
    }
};

//T.C = O(n log n)
//S.C = O(1)
