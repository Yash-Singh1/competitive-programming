class Solution {
  public:
    string removePair(string s) {
        string ans;
        for (auto c: s) {
            if (ans.size() > 0 && c == ans[ans.size() - 1]) {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        if (ans.size() == 0) {
            return "Empty String";
        }
        return ans;
    }
};