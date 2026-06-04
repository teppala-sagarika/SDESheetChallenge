//TUF
class Solution {
public:
   long long merge(vector<int>& nums,int l,int m,int h){
    vector<int> temp;
    int left=l;
    int ryt=m+1;
    long long c=0;
    while(left<=m && ryt<=h){
        if(nums[left]>nums[ryt]){
            temp.push_back(nums[ryt]);
            ryt++;
            c+=m-left+1;
        }
        else{
            temp.push_back(nums[left]);
            left++;
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
    return c;
   }
   long long mergeSort(vector<int>& nums,int l,int h){
    long long c=0;
    if(l>=h) return 0;
    int m=(l+h)/2;
    c+=mergeSort(nums,l,m);
    c+=mergeSort(nums,m+1,h);
    c+=merge(nums,l,m,h);
    return c;
   }
   long long int numberOfInversions(vector<int> nums) {
    int n=nums.size();
    return mergeSort(nums,0,n-1);
    }
};

//T.C = O(n log n)
//S.C = O(n)
