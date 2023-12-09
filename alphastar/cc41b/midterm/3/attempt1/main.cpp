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

  vector<vector<map<int,int>>> dp(2, vector<map<int,int>>(k+1));
  unordered_set<int> f;
  dp[0][k].insert({0, 1});
  for (int i{0}; i < n; ++i) {
    for (int j{k}; j >= 0; --j) {
      for (auto it = dp[0][j].begin(); it != dp[0][j].end(); it = next(it)) {
        f.insert(it->first);
        dp[1][j].insert(*it);
        // if (j && it->first + c[i] <= 10000) {
          dp[0][j-1].insert({it->first + c[i], 1});
        // }
        // if (j) dp[0][j-1].insert(*it);
      }
    }
    if (i<n-1) {
      swap(dp[0], dp[1]);
      for (int j{k}; j >= 0; --j) {
        dp[1][j].clear();
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
