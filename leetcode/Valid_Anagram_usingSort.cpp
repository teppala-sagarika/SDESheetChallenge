//using sorting

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
//T.C = O(n log n)
//S.C = O(log n) //Maximum stack depth = log n
