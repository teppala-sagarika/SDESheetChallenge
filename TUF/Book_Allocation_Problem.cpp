class Solution {
public:
    bool isPossible(vector<int> &nums, int m,int pgs){
        int stu=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=pgs){
                sum+=nums[i];
            }
            else{
                stu++;
                sum=nums[i];
            }
        }
        return stu<=m;
    }
    int findPages(vector<int> &nums, int m)  {
        int n=nums.size();
        if(n<m){
            return -1;
        }
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for(int x : nums)
            high += x;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(nums, m, mid)) {
                ans = mid;
                high = mid - 1;   
            }
            else {
                low = mid + 1;   
            }
        }
        return ans;
    }
};

//TC = O(n log(sum(nums)))
//SC = O(1)
