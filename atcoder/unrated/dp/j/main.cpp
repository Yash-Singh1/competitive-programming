#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  cout << fixed << setprecision(18);

  int a = 0, b=  0, c= 0;
  int x;
  for (int i{0}; i < n; ++i) {
    cin >> x;
    if (x == 1) ++a;
    else if (x == 2) ++b;
    else if (x == 3) ++c;
  }
  vector<vector<vector<ld>>> dp(305, vector<vector<ld>>(305, vector<ld>(305)));
  vector<vector<vector<ld>>> p(305, vector<vector<ld>>(305, vector<ld>(305)));
  dp[a][b][c] = 0.0L;
  p[a][b][c] = 1;
  for (int k{305}; k >= 0; --k) {
    for (int j{305}; j >= 0; --j) {
      for (int i{305}; i >= 0; --i) {
        if (!(i || j || k) || i + j + k > n) continue;
        ld pwaste{(((ld)(n-(i+j+k))/n))};
        ld evfail = (pwaste / (1 - pwaste)) + 1;
        dp[i][j][k] += evfail * p[i][j][k];
        // if (i == a && j == b && c == k) evfail = 0;
        // ++evfail;
        if (i) {
          ld pnext = ((ld)i/(i+j+k));
          dp[i - 1][j][k] += pnext * (dp[i][j][k]);
          p[i - 1][j][k] += p[i][j][k] * pnext;
        }
        if (j) {
          ld pnext = ((ld)j/(i+j+k));
          dp[i+1][j - 1][k] += pnext * (dp[i][j][k]);
          p[i+1][j - 1][k] += p[i][j][k] * pnext;
        }
        if (k) {
          ld pnext = ((ld)k/(i+j+k));
          dp[i][j+1][k-1] += pnext * (dp[i][j][k]);
          p[i][j+1][k-1] += p[i][j][k] * pnext;
        }
      }
    }
  }

  cout << dp[0][0][0] << "\n";

  return 0;
}
