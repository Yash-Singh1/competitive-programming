#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, n;
  cin >> k >> n;

  vector<int> c(n);
  for (int i{0}; i < n; ++i) {
    cin >> c[i];
  }
  sort(c.begin(), c.end());

  vector<vector<bitset<200001>>> dp(2, vector<bitset<200001>>(n));
  bitset<200001> f;
  dp[0][0][0] = 1;
  for (int j{k}; j >= 0; --j) {
    for (int i{0}; i < n; ++i) {
      for (int l{0}; l <= 200000; ++l) {
        if (!dp[0][i].test(l)) continue;
        // cout << *it << '\n';
        f.set(l);
        if (i < n-1) dp[0][i+1].set(l);
        if (l + c[i] <= 200000) {
          dp[1][i].set(l + c[i]);
        }
        // if (j) dp[0][j-1].insert(*it);
      }
    }
    if (j) {
      swap(dp[0], dp[1]);
      //for (int i{0}; i < n; ++i) {
    //    dp[1][i].reset();
      //}
    }
  }

  for (int i{0}; i < 200000; ++i) {
    if (!f.test(i+1)) {
      cout << i << '\n';
      break;
    }
  }

  return 0;
}
