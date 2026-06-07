class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int curCnt = 1;
        int lastSmall = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == lastSmall) {
                continue; // Ignore duplicates
            }
            else if (nums[i] == lastSmall + 1) {
                curCnt++;
            }
            else {
                curCnt = 1;
            }

            lastSmall = nums[i];
            longest = max(longest, curCnt);
        }

        return longest;
    }
};

//T.C = O(nlogn)
//S.C = O(1)
