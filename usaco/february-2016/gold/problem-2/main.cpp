#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cbarn2.in", "r", stdin);
  freopen("cbarn2.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  vector<int> req(n);
  int tot{0};
  for (int i{0}; i < n; ++i) {
    cin >> req[i];
    tot += req[i];
  }

  // Prefix sums precomputed for DP
  vector<int> restp(n);
  for (int i{0}; i < n; ++i) {
    int sm{0};
    for (int j{i}; j < (i+n); ++j) {
      sm += (j - i) * req[j%n];
    }
    restp[i] = sm;
  }
  vector<int> p(n);
  p[0] = req[0];
  for (int i{1}; i < n; ++i) {
    p[i] = p[i - 1] + req[i];
  }
  // Keep dp[i][start point][last point][left to place]
  vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(k+1, INT_MAX))));
  dp[0][0][0][k] = INT_MAX;
  int mn{INT_MAX};
  // I didn't notice that this is consecutive not range based
  // The only change would be that placing something would result in subtraction of the distance before
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j <= i; ++j) {
      for (int l{0}; l <= i; ++l) {
        for (int m{k}; m >= 0; --m) {
          if (dp[i][j][l][m] == INT_MAX && !(j == 0 && l == 0 && m == k)) continue;
          // if (dp[i][j][l][m] < mn) {
          //   cout << i << " " << j << " " << l << " " << m << "\n";
          // }
          mn = min(mn, dp[i][j][l][m]);
          dp[i + 1][j][l][m] = min(dp[i + 1][j][l][m], dp[i][j][l][m]);
          if (m == k) {
            dp[i + 1][i + 1][i + 1][k - 1] = min(dp[i + 1][i + 1][i + 1][k - 1], restp[i]);
          } else if (m) {
            dp[i + 1][j][i + 1][m - 1] = min(dp[i + 1][j][i + 1][m - 1], dp[i][j][l][m] - (i - l + 1) * (tot-(p[i - 1] - ((j-1) ? p[j - 2] : 0))));
            // if (m == k - 1) {
            //   // we need to subtract other half from i and add half near j
            //   // need equation for above
            //   // start: (j+i)/2, end: ((n+i+j)/2)%n sub from i and add for j
            //   int start{(j+i)/2}, end{((n+j+i)/2)%n};
            //   int sm{dp[i][j][l][m]};
            //   if (end < start) {
            //     sm -= p[j - 1][n - 1] - (start ? p[j - 1][start - 1] : 0) - p[j - 1][end];
            //     sm += p[i][n - 1] - (start ? p[i][start - 1] : 0) - p[i][end];
            //   } else {
            //     sm -= p[j - 1][end] - (start ? p[j - 1][start - 1] : 0);
            //     sm += p[i][end] - (start ? p[i][start - 1] : 0);
            //   }
            //   dp[i + 1][j][i + 1][k - 2] = min(dp[i + 1][j][i + 1][k - 2], sm);
            // } else {
            //   // Now we have multiple points in place and we need to insert another one
            //   // start: (i + l) / 2
            //   // end: ((n + i + j) / 2) % n
            //   // same idea as above
            //   int start{(l+i)/2}, end{((n+j+i)/2)%n};
            //   int sm{dp[i][j][l][m]};
            //   if (end < start) {
            //     sm -= p[j - 1][n - 1] - (start ? p[j - 1][start - 1] : 0) - p[j - 1][end];
            //     sm += p[i][n - 1] - (start ? p[i][start - 1] : 0) - p[i][end];
            //   } else {
            //     sm -= p[j - 1][end] - (start ? p[j - 1][start - 1] : 0);
            //     sm += p[i][end] - (start ? p[i][start - 1] : 0);
            //   }
            //   dp[i + 1][j][i + 1][m - 1] = min(dp[i + 1][j][i + 1][m - 1], sm);
            // }
          }
        }
      }
    }
  }

  cout << mn << "\n";

  return 0;
}
