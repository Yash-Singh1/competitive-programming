class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        ++digits[digits.size() - 1];
        if (digits[digits.size() - 1] == 10) {
            digits[digits.size() - 1] = 0;
            bool begin {digits.size() == 1 ? true : false};
            for (int i{static_cast<int>(digits.size()) - 2}; i >= 0; --i) {
                ++digits[i];
                if (digits[i] != 10) {
                    break;
                } else {
                    digits[i] = 0;
                    if (i == 0) {
                        begin = true;
                    }
                }
            }
            if (begin) digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
