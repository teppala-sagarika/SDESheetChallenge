class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int i=0;
        for(int x:st){
            nums[i]=x;
            i++;
        }
        return st.size();
    }
};

//T.C = O(n log n)+ O(n)
//S.C = O(n)
