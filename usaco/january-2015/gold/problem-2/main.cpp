#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("movie.in", "r", stdin);
  freopen("movie.out", "w", stdout);

  int n, l;
  cin >> n >> l;

  vector<vector<int>> schedule(n);
  vector<int> duration(n);
  int sz;
  for (int i{0}; i < n; ++i) {
    cin >> duration[i] >> sz;
    schedule[i].resize(sz);
    for (int j{0}; j < sz; ++j) {
      cin >> schedule[i][j];
    }
  }

  vector<vector<vector<int>>> next(n, vector<vector<int>>(n));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (i != j) {
        next[i][j].resize(schedule[i].size());
        for (int k{0}; k < (int)schedule[i].size(); ++k) {
          auto it = upper_bound(schedule[j].begin(), schedule[j].end(), schedule[i][k] + duration[i]);
          if (it != schedule[j].begin()) {
            if ((*prev(it)) + duration[j] > schedule[i][k] + duration[i]) {
              next[i][j][k] = prev(it) - schedule[j].begin();
            } else {
              next[i][j][k] = -1;
            }
          } else {
            next[i][j][k] = -1;
          }
        }
      }
    }
  }

  // {movie, showing}
  vector<pii> dp(1<<n, {-1, -1});
  for (int i{(1<<n)-1}; i > 0; --i) {
    int b{i};
    while (b) {
      if (dp[i].first == -1) {
        if (schedule[__builtin_ctz(b)][0] == 0 && (dp[i ^ LSOne(b)].first == -1 || duration[__builtin_ctz(b)] + schedule[__builtin_ctz(b)][0] > duration[dp[i ^ LSOne(b)].first] + schedule[dp[i ^ LSOne(b)].first][dp[i ^ LSOne(b)].second])) {
          dp[i ^ LSOne(b)] = {__builtin_ctz(b), 0};
        }
      } else {
        if (next[dp[i].first][__builtin_ctz(b)][dp[i].second] != -1 && (dp[i ^ LSOne(b)].first == -1 || duration[__builtin_ctz(b)] + schedule[__builtin_ctz(b)][next[dp[i].first][__builtin_ctz(b)][dp[i].second]] > duration[dp[i ^ LSOne(b)].first] + schedule[dp[i ^ LSOne(b)].first][dp[i ^ LSOne(b)].second]))
          dp[i ^ LSOne(b)] = {__builtin_ctz(b), next[dp[i].first][__builtin_ctz(b)][dp[i].second]};
      }
      b -= LSOne(b);
    }
  }

  int ans{INT_MAX};
  for (int i{0}; i < (1<<n); ++i) {
    if (dp[i].first != -1 && duration[dp[i].first] + schedule[dp[i].first][dp[i].second] >= l) {
      ans = min(ans, n-__builtin_popcount(i));
    }
  }

  cout << (ans==INT_MAX?-1:ans) << '\n';

  return 0;
}
