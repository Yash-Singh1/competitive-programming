class Solution {
public:
    bool isSubsequence(string s, string t) {
       int pos = 0;
       for (auto &c: t) {
         if (c == s[pos]) ++pos;
       }
       return pos == s.size();
    }
};