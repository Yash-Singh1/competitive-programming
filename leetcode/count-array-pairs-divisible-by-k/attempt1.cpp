// WA Attempt #1

class Solution {
public:
    long long gcd(int a, int b) {
        if (a % b == 0) {
            return b;
        } else {
            return gcd(b, a % b);
        }
    }
    long long countPairs(vector<int>& nums, int k) {
        map<int, int> m;
        long long ans{0};
        for (auto num: nums) {
            if ((num % k) != 0 && gcd(num % k, k) > 1 && m[(k / (num % k)) % k]) {
                if (((k / (num % k)) % k) != 0) ans += m[(k / (num % k)) % k];
            }
            m[num % k]++;
        }
        if (m[0]) {
            ans += m[0] * (nums.size() - 1);
            int f{(m[0] * max(m[0] - 1, 1))};
            if (m[0] > 1) {
                f /= 2;
                ans -= f;
            }
        }
        return ans;
    }
};
