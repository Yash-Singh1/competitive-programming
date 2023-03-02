#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#define LSOne(S) (S & -S)

ld dist(int x1, int y1, int x2, int y2) {
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<pair<int,int>,int>> mice(n+1);
  for (int i{0}; i < n; ++i) {
    cin >> mice[i].first.first >> mice[i].first.second >> mice[i].second;
  }
  mice[n] = {{0, 0}, 0};

  ld m;
  cin >> m;

  vector<ld> pow(n+1);
  pow[0] = 1.0L;
  for (int i{1}; i <= n; ++i) {
    pow[i] = pow[i - 1] * m;
  }

  ld l{1.0L/1e4L}, r{1e18L};
  for (int i{0}; i < 70; ++i) {
    ld mid{(l+r)/2};
    vector<vector<int>> dp(1<<n, vector<int>(n+1, INT_MAX));
    dp[(1<<n)-1][n] = 0;
    bool ans{0};
    for (int i{(1<<n)-1}; i >= 0; --i) {
      for (int j{0}; j <= n; ++j) {
        if (dp[i][j] == INT_MAX) continue;
        if (!i) {
          ans = 1;
          break;
        }
        int b{i};
        while (b) {
          ld time{dist(mice[__builtin_ctz(b)].first.first, mice[__builtin_ctz(b)].first.second, mice[j].first.first, mice[j].first.second) / (pow[n-__builtin_popcount(i)] * mid)};
          if (dp[i] + time <= mice[__builtin_ctz(b)].second) {
            dp[i^LSOne(b)][__builtin_ctz(b)] = min(dp[i^LSOne(b)][__builtin_ctz(b)], dp[i][j] + time);
          }
          b -= LSOne(b);
        }
      }
    }
    if (ans) {
      r = mid;
    } else [
      l = mid;
    ]
  }

  cout << l << '\n';

  return 0;
}
