#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    bool finished[m];
    int finc{0};
    pair<string, int> inout[m];
    for (int i{0}; i < m; ++i) {
      finished[i] = 0;
      cin >> inout[i].first >> inout[i].second;
    }
    bool success{1};
    while (finc < m) {
      int everyones{-1};
      bool sameo{1};
      for (int i{0}; i < m; ++i) {
        if (finished[i]) continue;
        if (inout[i].second != everyones) {
          if (everyones == -1) {
            everyones = inout[i].second;
          } else {
            sameo = 0;
            break;
          }
        }
      }
      if (sameo) {
        break;
      }
      bool foundsm{0};
      for (int i{0}; i < n; ++i) {
        int oneo{-1};
        int zero{-1};
        bool consistento{1}, consistentz{1};
        for (int j{0}; j < m; ++j) {
          if (finished[j]) continue;
          if (inout[j].first[i] == '1') {
            if (oneo == -1) {
              oneo = inout[j].second;
            } else {
              if (oneo != inout[j].second) {
                consistento = 0;
              }
            }
          } else {
            if (zero == -1) {
              zero = inout[j].second;
            } else if (zero != inout[j].second) {
              consistentz = 0;
            }
          }
        }
        consistento = consistento && oneo != -1;
        consistentz = consistentz && zero != -1;
        if (consistento) {
          for (int j{0}; j < m; ++j) {
            if (!finished[j] && inout[j].first[i] == '1' && inout[j].second == oneo) {
              finished[j] = 1;
              ++finc;
            }
          }
          foundsm = 1;
        }
        if (consistentz) {
          for (int j{0}; j < m; ++j) {
            if (!finished[j] && inout[j].first[i] == '0' && inout[j].second == zero) {
              finished[j] = 1;
              ++finc;
            }
          }
          foundsm = 1;
        }
        if (foundsm) break;
      }
      if (!foundsm) {
        success = 0;
        break;
      }
    }
    if (success) {
      cout << "OK\n";
    } else {
      cout << "LIE\n";
    }
  }

  return 0;
}
