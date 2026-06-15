class Solution{
    public:
    struct data{
        int start;
        int end;
    };
    static bool comp(data val1,data val2){
        return val1.end<val2.end;
    }
    int maxMeetings(vector<int>& start, vector<int>& end){
        int n=start.size();
        data arr[n];
        for(int i=0;i<n;i++){
            arr[i].start=start[i];
            arr[i].end=end[i];
        }
        sort(arr,arr+n,comp);
        int c=1;
        int tym=arr[0].end;
        for(int i=1;i<n;i++){
            if(arr[i].start>tym){
                c++;
                tym=arr[i].end;
            }
        }
        return c;
    }
};

//T.C = O(n log n)
//S.C = O(n)
