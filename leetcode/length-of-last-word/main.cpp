class Solution {
public:
    int lengthOfLastWord(string s) {
        int l{0};
        int lr{0};
        for (auto ch: s) {
            if (ch == ' ') {
                lr = (l == 0 ? lr : l);
                l = 0;
            } else {
                ++l;
                lr = l;
            }
        }
        return lr;
    }
};
