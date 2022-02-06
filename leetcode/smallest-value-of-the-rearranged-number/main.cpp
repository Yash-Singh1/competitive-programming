class Solution {
public:
  long long smallestNumber(long long num) {
      char digitsfr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
      if (num < 0) {
        vector<int> digits;
        while (num <= -10) {
          digits.insert(digits.begin(), num % -10);
          num -= num % -10;
          num /= 10;
        }
        digits.insert(digits.begin(), num);
        sort(digits.begin(), digits.end(), greater<int>());
        string numstr {"-"};
        for (unsigned long i {digits.size() - 1}; i > 0; --i) {
          cout << i << digits[i] << abs(digits[i]) << digitsfr[abs(digits[i])] << endl;
          numstr += digitsfr[abs(digits[i])];
        }
        numstr += digitsfr[abs(digits[0])];
        return std::stoll(numstr);
      } else {
        vector<int> digits;
        while (num >= 10) {
          digits.insert(digits.begin(), num % 10);
          num -= num % 10;
          num /= 10;
        }
        digits.insert(digits.begin(), num);
        sort(digits.begin(), digits.end());
        if (digits[0] == 0) {
          for (int i{0}; i < digits.size(); ++i) {
            if (digits[i] != 0) {
              digits[0] = digits[i];
              digits[i] = 0;
              break;
            }
          }
        }
        string numstr;
        for (int i {0}; i < digits.size(); ++i) {
          numstr += digitsfr[digits[i]];
        }
        return std::stoll(numstr);
      }
  }
};
