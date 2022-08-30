class Solution {
public:
    int myAtoi(string s) {
        long long pos{0};
        while (s[pos] == ' ') {
            ++pos;
        }
        bool sign{1};
        if (s[pos] == '+') {
            ++pos;
        } else if (s[pos] == '-') {
            sign = 0;
            ++pos;
        }
        if (s[pos] - '0' > 9 && s[pos] - '0' < 0) {
            return 0;
        }
        long long ans{0};
        while (s[pos] - '0' <= 9 && s[pos] - '0' >= 0) {
            ans *= 10;
            ans += s[pos] - '0';
            if (ans > 2147483648) {
                ans = 2147483648;
            }
            ++pos;
        }
        if (sign) {
            if (ans == 2147483648) {
                ans = 2147483647;
            }
        } else {
            ans *= -1;
        }
        return ans;
    }
};
