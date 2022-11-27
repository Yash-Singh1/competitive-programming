#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;
    int a[2*n];
    int mxi{-1};
    int mx{0};
    for (int i{0}; i < 2*n; ++i) {
      cin >> a[i];
      if (a[i] > mx) {
        mxi = i;
        mx = a[i];
      }
    }
    a[mxi] = a[2*n-1];
    a[2*n-1] = mx;
    bool figured{0};
    pair<int,int>ops[n];
    int op;
    ops[0].first = a[2*n-1];
    for (int j{0}; j < 2*n-1; ++j) {
      map<int, int> s;
      for (int i{0}; i < 2*n-1; ++i) {
        if (i != j) {
          ++s[a[i]];
        }
      }
      ops[0].second = a[j];
      int cur{a[2*n-1]};
      bool rly{1};
      op = 1;
      while (s.size() > 0) {
        bool gotee{0};
        for (auto it = s.rbegin(); it != s.rend(); it = next(it)) {
          if (s.find(cur - it->first) != s.end() && (cur-it->first != it->first || it->second >= 2)) {
            --s[it->first];
            --s[cur - it->first];
            int v{it->first};
            if (it->second == 0) {
              s.erase(next(it).base());
            }
            if (s.find(cur - v) != s.end() && s[cur - v] == 0) {
              s.erase(cur - v);
            }
            ops[op] = {v, cur - v};
            cur = max(v, cur - v);
            gotee = 1;
            ++op;
            break;
          }
        }
        if (!gotee) {
          rly = 0;
          break;
        }
      }
      if (rly) {
        figured = 1;
        break;
      }
    }

    if (!figured) {
      cout << "NO\n";
    } else {
      cout << "YES\n" << ops[0].first + ops[0].second << "\n";
      for (int i{0}; i < n; ++i) {
        cout << ops[i].first << " " << ops[i].second << "\n";
      }
    }
  }

  return 0;
}
