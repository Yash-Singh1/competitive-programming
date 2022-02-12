class Solution {
public:
    bool isPalindrome(int x) {
        string num {std::to_string(x)};
        string num2 {std::to_string(x)};
        reverse(num.begin(), num.end());
        if (num == num2) {
          return true;
        }
        return false;
    }
};
