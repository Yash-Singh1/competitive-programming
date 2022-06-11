class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        if (a.size() != b.size()) {
            return false;
        }
        map<char, int> m;
        for (auto c: a) {
            m[c]++;
        }
        for (auto c: b) {
            m[c]--;
        }
        for (const auto &p : m) {
            if (p.second != 0) {
                return false;
            }
        }
        return true;
    }

};
