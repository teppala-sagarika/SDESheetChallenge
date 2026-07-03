//using only 1 single hash map 

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        for (char c : t) {
            mp[c]--;
            if (mp[c] < 0)
                return false;
        }
        return true;
    }
};
//T.C = O(n)
//S.C = O(k) , k can be equal to n in worst case so S.C = O(n)
