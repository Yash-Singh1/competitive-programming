#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
  map<int,int> primeidx;
  vector<int> mdivb(61), mdiv(61);
  int primcur{0};
  for (auto &prime: primes) {
    for (int j{prime}; j <= 60; j += prime) {
      mdiv[j] = prime;
    }
    primeidx[prime] = primcur;
    ++primcur;
  }
  for (int k{2}; k <= 60; ++k) {
    int x{k};
    int bll{0};
    while (x > 1) {
      bll |= (1<<primeidx[mdiv[x]]);
      x /= mdiv[x];
    }
    mdivb[k] = bll;
  }
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> dp(n+1, vector<int>(1<<17, INT_MAX));
  vector<vector<pii>> val(n + 1, vector<pii>(1<<17, {-1, -1}));
  dp[0][0] = 0;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < 1<<17; ++j) {
      if (dp[i][j] == INT_MAX) continue;
      for (int k{1}; k <= 60; ++k) {
        if (mdivb[k] & j) continue;
        if (dp[i][j] + abs(a[i] - k) < dp[i + 1][mdivb[k] ^ j]) {
          dp[i + 1][mdivb[k] ^ j] = dp[i][j] + abs(a[i] - k);
          val[i + 1][mdivb[k] ^ j] = {k, j};
        }
      }
    }
  }

  int mni{-1}, mn{INT_MAX};
  for (int i{0}; i < (1<<17); ++i) {
    if (dp[n][i] < mn) {
      mn = dp[n][i];
      mni = i;
    }
  }

  int cur{mni};
  vector<int> ans(n);
  for (int i{n - 1}; i >= 0; --i) {
    ans[i] = val[i+1][cur].first;
    cur = val[i+1][cur].second;
  }

  for (auto &ansp: ans) cout << ansp << " ";
  cout << "\n";

  return 0;
}
