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

  vector<vector<set<int>>> dp(2, vector<set<int>>(n));
  unordered_set<int> f;
  dp[0][0].insert(0);
  for (int j{k}; j >= 0; --j) {
    for (int i{0}; i < n; ++i) {
      for (auto it = dp[0][i].begin(); it != dp[0][i].end(); it = next(it)) {
        // cout << *it << '\n';
        f.insert(*it);
        if (i < n-1) dp[0][i+1].insert(*it);
        // if (*it + c[i] <= 50000) {
          dp[1][i].insert(*it + c[i]);
        // }
        // if (j) dp[0][j-1].insert(*it);
      }
    }
    if (j) {
      swap(dp[0], dp[1]);
      for (int i{0}; i < n; ++i) {
        dp[1][i].clear();
      }
    }
  }

  int s{1};
  while (f.find(s) != f.end()) {
    ++s;
  }

  cout << s-1 << '\n';

  return 0;
}
