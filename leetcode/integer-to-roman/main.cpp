class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int place{1};
        while (num > 0) {
            int offset {num % 10};
            if (offset != 0) {
            switch (place) {
                case 1:
                {
                    if (offset < 4) {
                        ans = string(offset, 'I') + ans;
                    } else if (offset == 4) {
                        ans = "IV" + ans;
                    } else if (offset < 9) {
                        ans = "V" + string(offset - 5, 'I') + ans;
                    } else if (offset == 9) {
                        ans = "IX" + ans;
                    }
                    break;
                }
                case 10:
                {
                    if (offset < 4) {
                        ans = string(offset, 'X') + ans;
                    } else if (offset == 4) {
                        ans = "XL" + ans;
                    } else if (offset < 9) {
                        ans = "L" + string(offset - 5, 'X') + ans;
                    } else if (offset == 9) {
                        ans = "XC" + ans;
                    }
                    break;
                }
                case 100:
                {
                    if (offset < 4) {
                        ans = string(offset, 'C') + ans;
                    } else if (offset == 4) {
                        ans = "CD" + ans;
                    } else if (offset < 9) {
                        ans = "D" + string(offset - 5, 'C') + ans;
                    } else if (offset == 9) {
                        ans = "CM" + ans;
                    }
                    break;
                }
                case 1000:
                {
                    ans = string(offset, 'M') + ans;
                    break;
                }
            }
            }
            num -= offset;
            num /= 10;
            place *= 10;
        }
        return ans;
    }
};
