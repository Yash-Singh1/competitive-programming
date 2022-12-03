map<char,int> f;

class Solution {
public:
    string frequencySort(string s) {
        f.clear();
        for (auto &c: s) {
            ++f[c];
        }
        set<pair<int,int>>se;
        for (auto it = f.begin(); it != f.end(); it = next(it)) {
            se.insert({it->second, it->first});
        }
        string ans;
        for (auto it = se.rbegin(); it != se.rend(); it = next(it)) {
            ans += string(it->first, it->second);
        }
        return ans;
    }
};
