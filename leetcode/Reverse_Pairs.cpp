// ────────────────────────────────────────────────────────────
// Problem : Reverse Pairs
// Platform: LeetCode
// URL     : https://leetcode.com/problems/reverse-pairs/submissions/2024112893/
// Language: cpp
// Date    : 6/6/2026, 3:46:14 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n log n)
// Space Complexity: O(n)
// Notes           : Merge Sort
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int c=0;
    void merge(vector<int> &nums,int l,int m,int h){
        vector<int> temp;
        int left=l;
        int ryt=m+1;
        while(left<=m && ryt<=h){
            if(nums[left]<=nums[ryt]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[ryt]);
                ryt++;
            }
        }
        while(left<=m){
            temp.push_back(nums[left]);
            left++;
        }
        while(ryt<=h){
            temp.push_back(nums[ryt]);
            ryt++;
        }
        for(int i=l;i<=h;i++){
            nums[i]=temp[i-l];
        }
    }

    void countPairs(vector<int> &nums,int l,int m,int h){
        int ryt=m+1;
        for(int left=l;left<=m;left++){
            while(ryt<=h && (long long)nums[left]>2LL*nums[ryt]){
                ryt++;
            }
        c+=ryt-(m+1);
        }
    }

    void mergeSort(vector<int> &nums,int l,int h){
        if(l>=h) return;
        int m=(l+h)/2;
        mergeSort(nums,l,m);
        mergeSort(nums,m+1,h);
        countPairs(nums,l,m,h);
        merge(nums,l,m,h);
    }
    int reversePairs(vector<int>& nums) {
        //Merge Sort
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return c;
    }
};