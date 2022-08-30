class Solution {
public:
    bool areNumbersAscending(string s) {
        int num{-1};
        long snuma{0};
        bool snumf{0};
        for (int i{0}; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (!snumf) {
                    //cout << snuma << " " << num << " " << i << endl;
                    if (snuma <= num) {
                        return false;
                    }
                    num = snuma;
                }
                snumf = 0;
                snuma = 0;
            } else if (s[i] - '0' < 0 || s[i] - '0' > 9) {
                snumf = 1;
            } else if (!snumf && s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                snuma *= 10;
                snuma += s[i] - '0';
            }
        }
                if (!snumf) {
                    //cout << snuma << " " << num << " " << i << endl;
                    if (snuma <= num) {
                        return false;
                    }
                    num = snuma;
                }
        return true;
    }
};
