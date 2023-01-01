#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("time.in", "r", stdin);
  freopen("time.out", "w", stdout);

  int N, M, C;
  cin >> N >> M >> C;

  vector<int> profit(N);
  for (int n{0}; n < N; ++n) {
    cin >> profit[n];
  }

  vector<int> g[N];
  int x, y;
  while (M--) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
  }

  vector<vector<int>> dp(1001, vector<int>(N, -1));
  dp[0][0] = 0;
  int ans{0};
  for (int day{0}; day < 1000; ++day) {
    for (int i{0}; i < N; ++i) {
      if (dp[day][i] != -1) {
        for (auto &ne: g[i]) {
          dp[day + 1][ne] = max(dp[day + 1][ne], dp[day][i] + profit[ne]);
        }
      }
    }
    ans = max(ans, dp[day][0] - (day * day * C));
  }

  cout << ans << "\n";

  return 0;
}
