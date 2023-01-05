#include <bits/stdc++.h>

using namespace std;

class ChristmasSongTrauma  {
  public:
    double fewest(vector <int> playTime, int visitTime) {
        if (playTime.size() == 1) return 1.0;
        int sm{0};
        for (auto &p: playTime) sm += p;
        visitTime %= sm;
        vector<int> ps(playTime.size() * 2 + 1);
        for (int i{0}; i < playTime.size() * 2; ++i) {
            ps[i + 1] = ps[i] + playTime[i  % playTime.size()];
        }
        int mn{INT_MAX};
        for (int i{0}; i < playTime.size(); ++i) {
            int val = lower_bound(ps.begin(), ps.end(), visitTime + ps[i]) - (ps.begin() + i);
            if (val < mn) {
                mn = val;
            }
        }
        cout << mn << "\n";
        int totGood{0};
        for (int i{0}; i < playTime.size(); ++i) {
            int val = lower_bound(ps.begin(), ps.end(), visitTime + ps[i]) - (ps.begin() + i);
            if (val == mn) {
                cout << i << " " << min(*lower_bound(ps.begin(), ps.end(), visitTime + ps[i]) - (ps[i] + visitTime), playTime[i]) << "\n";
                totGood += min(*lower_bound(ps.begin(), ps.end(), visitTime + ps[i]) - (ps[i] + visitTime) + 1, playTime[i]);
            }
        }
        return (double)totGood / sm;
    }
};
