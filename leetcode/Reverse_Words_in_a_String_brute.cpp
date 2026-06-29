class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token="";
        string res="";
        while(ss>>token){
            res=token+" "+res;
        }
        int n=res.length();
        return res.substr(0,n-1);
    }
};

//TC = O(n^2)
//SC = O(n)
