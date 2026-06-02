class Solution {
public:
    void sortColors(vector<int>& a) {
        int n=a.size();
        int r=0,w=0,b=0;
        for(int i=0;i<n;i++){
           if(a[i]==0){
            r++;
           }
           else if(a[i]==1){
            w++;
           }
           else{
            b++;
           }
        }
        for(int i=0;i<n;i++){
            if(i<r){
                a[i]=0;
            }
            else if(i<r+w){
                a[i]=1;
            }
            else{
                a[i]=2;
            }
        }
    }
};
