class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int l{0}, r{stalls[n-1] - stalls[0]}, ans{-1};
        while (l <= r) {
            int m{(l+r)/2};
            int pos{stalls[0]};
            int cleft{k};
            bool did{1};
            while (cleft) {
                auto query = lower_bound(stalls.begin(), stalls.end(), pos + m);
                --cleft;
                if (cleft && query == stalls.end()) {
                    did = 0;
                    break;
                } else if (!cleft) {
                    break;
                }
                pos = *query;
            }
            if (did) {
                l = m+1;
                ans = m;
            } else {
                r = m-1;
            }
        }
        return ans;
    }
};
