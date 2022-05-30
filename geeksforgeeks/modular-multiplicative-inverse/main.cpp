#include <cmath>

class Solution{
    public:
    int binPow(int a, int b, int m) {
        int ans {1};
        while (b > 0) {
            if (b % 2 == 1) {
                ans *= a;
                ans %= m;
            }
            a *= a;
            a %= m;
            b /= 2;
        }
        return ans;
    }
    
    bool coprime(int a, int b) {
        int max{a > b ? a : b};
        for (int i{2}; i < sqrt(max); ++i) {
            if (a % i == 0 && b % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    int modInverse(int a, int m)
    {
        a %= m;
        if (a * m - 2 == 1) {
            return m - 2;
        } else if (a * a % m == 1) {
            return a;
        } 
        if (!coprime(a, m)) {
            return -1;
        }
        int ans = binPow(a, m - 2, m) % m;
        return ans;
    }
};
