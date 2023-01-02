#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a(10000);
vector<vector<int>> dp(2, vector<int>(1000, -1));
int anse{0};

// int mx(int cur, int mid) {
//   if (dp[cur][mid] != -1) {
//     return dp[cur][mid];
//   }
//   if (cur == n) {
//     return 0;
//   }
//   int ans{INT_MIN};
//   int mxe{0};
//   for (int i{cur - mid}; i <= cur; ++i) {
//     mxe = max(a[i], mxe);
//   }
//   if (mid < k-1 && cur < n - 1) {
//     ans = mx(cur + 1, mid + 1);
//   }
//   ans = max(ans, mx(cur + 1, 0) + (mxe * (mid + 1)));
//   if (ans > anse) {
//     // cout << cur << " " << mid << "\n";
//     anse = ans;
//   }
//   return (dp[cur][mid] = ans);
// }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("teamwork.in", "r", stdin);
  freopen("teamwork.out", "w", stdout);

  cin >> n >> k;
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  // mx(0, 0);
  int cur{1};
  for (int i{n-1}; i >= 0; --i) {
    int mxe{0};
    for (int j{0}; j <= min(k - 1, i); ++j) {
      mxe = max(mxe, a[i - j]);
      if (j < k - 1 && i < n - 1) {
        dp[cur][j] = dp[1 - cur][j + 1];
      }
      dp[cur][j] = max((i == n - 1 ? 0 : dp[1 - cur][0]) + (mxe * (j + 1)), dp[cur][j]);
      // if (dp[i][j] > anse) {
      //   cout << i << " " << j << "\n";
      // }
      anse = max(anse, dp[cur][j]);
    }
    cur = 1 - cur;
  }
  cout << anse << "\n";

  // cout << "\n-----------\n\n";
  // for (int i{0}; i < n; ++i) {
  //   for (int j{0}; j < k; ++j) {
  //     cout << setfill('0') << setw(3) << dp[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  return 0;
}
