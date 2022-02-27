class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
      int ans{0};
      for (auto word: words) {
        if (word.rfind(pref, 0) == 0) {
          ++ans;
        }
      }
      return ans;
    }
};
