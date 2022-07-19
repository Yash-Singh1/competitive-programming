class Solution {
public:
    int tribonacci(int n) {
      long long a{0};
      long long b{1};
      long long c{1};
      for (int i{0}; i < n; ++i) {
        long long d{a + b + c};
        a = b;
        b = c;
        c = d;
      }
      return static_cast<int>(a);
    }
};
