class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (x == 1 || x == 0) return x;
        else if (x == -1) {
            if (n % 2 == 0) {
                return 1;
            }
            return -1;
        }
        while (n % 2 == 0) {
            x *= x;
            n /= 2;
        }
        double ans{x};
        if (n > 0) {
            for (int i{1}; i < n; ++i) {
                ans *= x;
            }
        } else if (n < 0) {
            ans = 1;
            for (int i{-1}; i >= n; --i) {
                ans /= x;
            }
        }
        return ans;
    }
};
