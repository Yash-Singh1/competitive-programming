class Solution {
public:
    int reverse(int x) {
        try {
          string b = std::to_string(x);
          std::reverse(b.begin(), b.end());
          int a{stoi(b)};
          if (x < 0) {
            a *= -1;
          }
          return a;
        } catch (const std::exception& e) {
          return 0;
        }
    }
};
