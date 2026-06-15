class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        vector<pair<double,int>> ratio;
        int n=val.size();
        for(int i=0;i<n;i++){
            ratio.push_back({(double)val[i]/wt[i],i});
        }
        sort(ratio.rbegin(),ratio.rend());
        int c=capacity;
        double ans=0;
        for(int i=0;i<n;i++){
            int idx=ratio[i].second;
            int w=wt[idx];
            int v=val[idx];
            if(c==0){
                break;
            }
            if(w<=c){
                c-=w;
                ans+=v;
            }
            else{
                ans+=(double)c/w*v;
                c=0;
            }
        }
        return ans;
    }
};
