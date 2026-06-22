class Solution {
public:
    bool canPlace(vector<int>& nums, int k, int dist) {
        int cows = 1;
        int last = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - last >= dist) {
                cows++;
                last = nums[i];
            }
            if(cows >= k)
                return true;
        }
        return false;
    }
    int aggressiveCows(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 1;
        int high = nums.back() - nums[0];
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canPlace(nums, k, mid)) {
                ans = mid;          // possible, try bigger distance
                low = mid + 1;
            }
            else {
                high = mid - 1;     // decrease distance
            }
        }
        return ans;
    }
};

//TC = O(n log n)
//SC = O(1)
