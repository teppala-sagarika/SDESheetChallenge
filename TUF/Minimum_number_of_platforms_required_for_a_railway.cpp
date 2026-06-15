class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        int n=Arrival.size();
        sort(Arrival.begin(),Arrival.end());
        sort(Departure.begin(),Departure.end());
        int i=0,j=0;
        int c=0,mx=0;
        while(i<n && j<n){
            if(Arrival[i]<=Departure[j]){
                c++;
                i++;
            }else{
                c--;
                j++;
            }
            mx=max(mx,c);
        }
        return mx;
    }
};

//T.C = O(n log n)
//S.C = O(1)
