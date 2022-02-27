class Solution {
public:
    int minSteps(string s, string t) {
        int total{0};
        sort(t.begin(), t.end());
        map<char, int> frequencies;
        char lastChar;
        for (int i{0}; i < t.size(); ++i) {
          if (lastChar == t[i]) {
            ++frequencies[lastChar];
          } else {
            lastChar = t[i];
            frequencies[lastChar] = 1;
          }
        }
        for (auto sChar: s) {
          if (frequencies.find(sChar) != frequencies.end() && frequencies[sChar] > 0) {
            --frequencies[sChar];
          } else {
            ++total;
          }
        }
        for (const auto & [key, value]: frequencies) {
          total += value;
        }
        return total;
    }
};
