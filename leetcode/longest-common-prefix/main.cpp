class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool works{true};
        string prefix;
        while (works) {
          if (prefix.size() == strs[0].size()) break;
          prefix += strs[0][prefix.size()];
          for (auto str: strs) {
            if (str.rfind(prefix, 0) == std::string::npos) {
              works = false;
              prefix.pop_back();
              break;
            }
          }
        }
        return prefix;
    }
};
