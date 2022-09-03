#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ++n;
    long long min{-1};
    vector<int> g;
    vector<int> l;
    while (--n) {
        char x;
        cin >> x;
        int y;
        cin >> y;
        if (x == 'G') {
            g.push_back(y);
        } else {
            l.push_back(y);
        }
    }
    sort(g.begin(), g.end());
    sort(l.begin(), l.end());
    long long ng{g.size()};
    long long nl{l.size()};
    for (int i{0}; i < ng; ++i) {
        long long loc{-1};
        for (int j{0}; j < nl; ++j) {
            if (l[j] >= g[i]) {
                loc = j;
                break;
            }
        }
        if (loc == -1) {
            if (min == -1 || min > nl) {
                min = nl;
            }
            if (min > ng) {
                min = ng;
            }
        } else {
            if (min == -1 || min > (ng - i) - 1 + loc) {
                min = (ng - i) - 1 + loc;
            }
        }
    }
    if (min == -1) {
        cout << 0;
    } else {
        cout << min;
    }
}
