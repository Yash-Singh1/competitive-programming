class Solution {
  public:
    int minOperation(string s) {
        string ans{s[0]};
        int tot{1};
        int n{s.size()};
        while (ans.size() < s.size()) {
            if ((n - ans.size() - ans.size()) > 0 && startsWith(s, ans, ans.size()) == true) {
                ans += ans;
                ++tot;
            } else {
                ans += s[ans.size()];
                ++tot;
            }
        }
        return tot;
    }
    
    bool startsWith(string s, string a, int start) {
        for (int i{start}; i < a.size() + start; ++i) {
            if (a[i - start] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
