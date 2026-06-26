class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                if(st.top()<arr[i]){
                    ans[i]=st.top();
                    break;
                }else{
                    st.pop();
                }
            }
            st.push(arr[i]);
        }
        return ans;
    }
};

//TC = O(n)
//SC = O(n)
