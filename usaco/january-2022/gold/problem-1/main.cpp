// http://usaco.org/index.php?page=viewproblem2&cpid=1185
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int mn{1000};
  vector<int> h(n);
  for (int i{0}; i < n; ++i) {
    cin >> h[i];
    if (h[i] < mn) mn = h[i];
  }

  // dp[pos][behind][next] = number of ways where we are deciding at pos, which has upper bound next, and everything behind is behind
  // Base:
  // dp[0][0][h[0]] = 1
  // dp[1][k][h[1]] = 1

  vector<vector<int>> dp1(1002, vector<int>(1002));
  vector<vector<int>> dp2(1002, vector<int>(1002));
  for (int l{0}; l <= h[0]; ++l) {
    dp1[l][h[1]] = 1;
  }

  // TODO: optimize
  for (int i{1}; i < n; ++i) {
    for (int j{0}; j <= 1000; ++j) {
      fill(dp2[j].begin(), dp2[j].end(), 0);
    }

    for (int j{0}; j <= 1000; ++j) {
      for (int k{0}; k <= h[i]; ++k) {
        if (!dp1[j][k]) continue;
        int nxmx{i < n - 1 ? h[i+1] : 0};
        if (k >= j) {
          dp2[j][nxmx] += dp1[j][k];
          if (dp2[j][nxmx] >= MOD) dp2[j][nxmx] -= MOD;
          dp2[j+1][nxmx] -= dp1[j][k];
          if (dp2[j+1][nxmx] < 0) dp2[j+1][nxmx] += MOD;
          dp2[j][nxmx+1] -= dp1[j][k];
          if (dp2[j][nxmx+1] < 0) dp2[j][nxmx+1] += MOD;
          dp2[j+1][nxmx+1] += dp1[j][k];
          if (dp2[j+1][nxmx+1] >= MOD) dp2[j+1][nxmx+1] -= MOD;
        }
        if (i < n-1 && j+1 <= k && j+1 <= nxmx + j) {
          int mxp{nxmx - ((min(k, nxmx + j))-j)};
          dp2[j][mxp] += dp1[j][k];
          if (dp2[j][mxp] >= MOD) dp2[j][mxp] -= MOD;
          dp2[j][nxmx] -= dp1[j][k];
          if (dp2[j][nxmx] < 0) dp2[j][nxmx] += MOD;
          dp2[j+1][mxp] -= dp1[j][k];
          if (dp2[j+1][mxp] < 0) dp2[j+1][mxp] += MOD;
          dp2[j+1][nxmx] += dp1[j][k];
          if (dp2[j+1][nxmx] >= MOD) dp2[j+1][nxmx] -= MOD;
          // [current][j + 1, min(k, nxmx + j)]
          // for (int l{j+1}; l <= k && l <= nxmx + j; ++l) {
          //   dp2[j][nxmx - (l-j)] += dp1[j][k];
          //   if (dp2[j][nxmx - (l-j)] >= MOD) dp2[j][nxmx - (l-j)] -= MOD;
          // }
        }
        if ((i%2) == 0 && 0 < j && 0 <= k) {
          dp2[0][nxmx] += dp1[j][k];
          if (dp2[0][nxmx] >= MOD) dp2[0][nxmx] -= MOD;
          dp2[0][nxmx+1] -= dp1[j][k];
          if (dp2[0][nxmx+1] < 0) dp2[0][nxmx+1] += MOD;
          dp2[min(j-1, k)+1][nxmx] -= dp1[j][k];
          if (dp2[min(j-1, k)+1][nxmx] < 0) dp2[min(j-1, k)+1][nxmx] += MOD;
          dp2[min(j-1, k)+1][nxmx+1] += dp1[j][k];
          if (dp2[min(j-1, k)+1][nxmx+1] >= MOD) dp2[min(j-1, k)+1][nxmx+1] -= MOD;
          // [0, min(j - 1, k)][nxmx]
          // for (int l{0}; l < j && l <= k; ++l) {
          //   dp2[l][nxmx] += dp1[j][k];
          //   if (dp2[l][nxmx] >= MOD) dp2[l][nxmx] -= MOD;
          // }
        }
      }
    }

    for (int j{0}; j <= 1000; ++j) {
      for (int k{0}; k <= 1000; ++k) {
        if (j) {
          dp2[j][k] += dp2[j - 1][k];
          if (dp2[j][k] < 0) dp2[j][k] += MOD;
          if (dp2[j][k] >= MOD) dp2[j][k] -= MOD;
        }
        if (k) {
          dp2[j][k] += dp2[j][k - 1];
          if (dp2[j][k] < 0) dp2[j][k] += MOD;
          if (dp2[j][k] >= MOD) dp2[j][k] -= MOD;
        }
        if (j && k) {
          dp2[j][k] -= dp2[j - 1][k - 1];
          if (dp2[j][k] < 0) dp2[j][k] += MOD;
          if (dp2[j][k] >= MOD) dp2[j][k] -= MOD;
        }
      }
    }

    swap(dp1, dp2);
  }

  int sm{0};
  for (int i{0}; i <= mn; ++i) {
    sm += dp1[i][0];
    if (sm >= MOD) sm -= MOD;
  }

  cout << sm << "\n";

  return 0;
}
