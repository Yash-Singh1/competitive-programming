#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

void minp(pii *a, pii val) {
  if (a->second < val.second) return;
  else {
    *a = val;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // store max occurrences up till point
  string s;
  cin >> s;

  int n{s.size()};
  vector<int> del(n);
  for (int i{0}; i < n; ++i) {
    cin >> del[i];
  }

  string search = "bessie";

  vector<int> mx(n+1);
  vector<int> pos(n+1);
  pos[0] = 0;
  mx[0] = 0;
  for (int i{0}; i < n; ++i) {
    if (s[i] == search[pos[i]]) {
      if (pos[i] == search.size()-1) {
        pos[i+1] = 0;
        mx[i+1] = mx[i]+1;
      } else {
        pos[i+1] = pos[i]+1;
        mx[i+1] = mx[i];
      }
    } else {
      pos[i+1] = pos[i];
      mx[i+1] = mx[i];
    }
  }

  // mx
  vector<vector<pii>> dp(n+1, vector<pii>(search.size()+1, {0, INT_MAX}));
  vector<vector<pii>> dp2(n+1, vector<pii>(search.size()+1, {0, INT_MAX}));
  dp[0][0].second = 0;
  dp2[0][0].second = 0;

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < search.size(); ++j) {
      for (int k{mx[i]-1}; k <= mx[i]; ++k) {
        if (dp[i][j].second != INT_MAX) {
        if (dp[i][j].first == mx[i+1] - 1) {
          minp(&dp[i+1][j], {dp[i][j].first, dp[i][j].second + del[i]});
        }
        if (dp[i][j].first == mx[i+1]) {
          minp(&dp2[i+1][j], {dp[i][j].first, dp[i][j].second + del[i]});
        }
        }
        if (dp2[i][j].second != INT_MAX) {
        if (dp2[i][j].first == mx[i+1] - 1) {
          minp(&dp[i+1][j], {dp2[i][j].first, dp2[i][j].second + del[i]});
        }
        if (dp2[i][j].first == mx[i+1]) {
          minp(&dp2[i+1][j], {dp2[i][j].first, dp2[i][j].second + del[i]});
        }
        }
        if (dp[i][j].second != INT_MAX) {
        if (dp[i][j].first == mx[i+1] - 1) {
          minp(&dp[i+1][0], {dp[i][j].first, dp[i][j].second});
        }
        if (dp[i][j].first == mx[i+1]) {
          minp(&dp2[i+1][0], {dp[i][j].first, dp[i][j].second});
        }
        }
        if (dp2[i][j].second != INT_MAX) {
        if (dp2[i][j].first == mx[i+1] - 1) {
          minp(&dp[i+1][0], {dp2[i][j].first, dp2[i][j].second});
        }
        if (dp2[i][j].first == mx[i+1]) {
          minp(&dp2[i+1][0], {dp2[i][j].first, dp2[i][j].second});
        }
        }
        if (search[j] == s[i]) {
          if (j == search.size() - 1) {
            if (dp[i][j].second != INT_MAX) {
            if (dp[i][j].first + 1 == mx[i+1] - 1) {
              minp(&dp[i+1][0], {dp[i][j].first + 1, dp[i][j].second});
            } else if (dp[i][j].first + 1 == mx[i+1]) {
              minp(&dp2[i+1][0], {dp[i][j].first + 1, dp[i][j].second});
            }
            }
            if (dp2[i][j].second != INT_MAX) {
            if (dp2[i][j].first + 1 == mx[i+1] - 1) {
              minp(&dp[i+1][0], {dp2[i][j].first + 1, dp2[i][j].second});
            } else if (dp2[i][j].first + 1 == mx[i+1]) {
              minp(&dp2[i+1][0], {dp2[i][j].first + 1, dp2[i][j].second});
            }
            }
          } 
          else {
            if (dp[i][j].second != INT_MAX) {
            if (dp[i][j].first == mx[i+1] - 1) {
              minp(&dp[i+1][j+1], {dp[i][j].first, dp[i][j].second});
            } else if (dp[i][j].first == mx[i+1]) {
              minp(&dp2[i+1][j+1], {dp[i][j].first, dp[i][j].second});
            }
            }
            if (dp2[i][j].second != INT_MAX) {
            if (dp2[i][j].first == mx[i+1] - 1) {
              minp(&dp[i+1][j+1], {dp2[i][j].first, dp2[i][j].second});
            } else if (dp2[i][j].first == mx[i+1]) {
              minp(&dp2[i+1][j+1], {dp2[i][j].first, dp2[i][j].second});
            }
            }
          }
        }
      }
    }
  }

  int ans{INT_MAX};
  for (int i{0}; i <= search.size(); ++i) {
    ans = min(ans, dp2[n][i].second);
  }

  cout << mx[n] << '\n' << ans << '\n';

  return 0;
}
