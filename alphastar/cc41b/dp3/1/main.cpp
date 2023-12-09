#include <bits/stdc++.h>

using namespace std;

struct Item {
  int w, v;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, c;
  cin >> n >> c;

  vector<Item> a(n);
  for (int i{0}; i < n; ++i) {
    cin >> a[i].w >> a[i].v;
  }

  vector<vector<int>> dp(n+1, vector<int>(c+1));
  dp[0][c] = 0;
  for (int i{0}; i < n; ++i) {
    for (int j{c}; j >= 0; --j) {
      dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
      if (j >= a[i].w) dp[i+1][j-a[i].w] = max(dp[i][j]+a[i].v, dp[i+1][j-a[i].w]);
    }
  }

  int mx{-1};
  for (int i{0}; i <= c; ++i) {
    mx = max(mx, dp[n][i]);
  }

  cout << mx << '\n';

  return 0;
}
