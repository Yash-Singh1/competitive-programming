class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
                    if (n <= 0) {
                return true;
            }
        int last{-1};
        int lastC{0};
        int posLast{-2};
        vector<pair<int, int>> v;
        for (int i{0}; i < m; ++i) {
            if (last == 0) {
                if (seats[i] == 0) {
                    ++lastC;
                } else {
                    v.push_back({lastC,posLast});
                    last = 1;
                    lastC = 0;
                    posLast = -2;
                }
            } else {
                if (seats[i] == 0) {
                    if (i == 0) {
                        posLast = -1;
                    } else {
                        posLast = 0;
                    }
                    lastC = 1;
                    last = 0;
                }
            }
        }
        if (last == 0) {
            v.push_back({lastC,(posLast == -1 ? 2 : 1)});
        }
        for (auto s: v) {
            if (s.second == -1 || s.second == 1) {
                n -= s.first / 2;
            } else if (s.second == 2) {
                n -= (s.first + 1) / 2;
            } else {
                n -= (s.first - 1) / 2;
            }
            if (n <= 0) {
                return true;
            }
        }
        return false;
    }
};
