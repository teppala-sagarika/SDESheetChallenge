class Solution{   
public:
    bool solve(int i,int n,vector<int>& arr, int target){
        if(target==0){
            return true;
        }
        if(i>=n){
            return false;
        }
        bool notake=solve(i+1,n,arr,target);
        bool take=false;
        if(arr[i]<=target)
        take=solve(i+1,n,arr,target-arr[i]);
        return take||notake;
    }
    bool isSubsetSum(vector<int>arr, int target){
        int n=arr.size();
        return solve(0,n,arr,target);
    }
};

//T.C = O(2^n)
//S.C = O(n)
