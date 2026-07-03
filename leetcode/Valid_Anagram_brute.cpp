class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        map<char,int> mp1,mp2;
        for(int i=0;i<n;i++){
            mp1[s[i]]++;
        }
        for(int i=0;i<m;i++){
            mp2[t[i]]++;
        }
        for(auto &p:mp1){
            int a=p.first;
            if(mp2.find(a)==mp2.end()){
                return false;
            }else{
                if(mp1[a]!=mp2[a]){
                    return false;
                }
            }
        }
        return true;
    }
};

//T.C = O(n)
//S.C = O(k) , k can be equal to n in worst case so S.C = O(n)
