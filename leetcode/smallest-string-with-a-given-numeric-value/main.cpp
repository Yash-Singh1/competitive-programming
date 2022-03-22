class Solution {
public:
    string getSmallestString(int n, int k) {
        int starters {std::min(k - n + 1, 26)};
        char dump = starters + 96;
        string ans {dump};
        --n;
        k -= starters;
        while (k > 0) {
            starters = std::min(k - n + 1, 26);
            dump = starters + 96;
            ans.push_back(dump);
            --n;
            k -= starters;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
