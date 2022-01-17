class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> parts;
        for (size_t i {0}; i < s.length(); i += k) {
          string part {s.substr(i, s.length() - i >= k ? k : s.length() - i)};
          part += string(k - part.length(), fill);
          parts.push_back(part);
        }
        return parts;
    }
};
