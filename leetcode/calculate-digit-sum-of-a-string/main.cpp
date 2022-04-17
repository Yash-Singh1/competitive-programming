class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
          vector<string> parts;
          for (int i {0}; i < s.length(); i += k) {
            parts.push_back(s.substr(i, k));
          }
          s = "";
          for (auto part: parts) {
            int sum {0};
            for (auto character: part) {
              sum += character - '0';
            }
            s += std::to_string(sum);
          }
        }
      return s;
    }
};
