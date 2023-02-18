#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  set<char> unique;
  for (auto &c: s) unique.insert(c);
  map<char,int> um;
  int dist{0};
  for (auto it = unique.begin(); it != unique.end(); it = next(it)) {
    um[*it] = dist;
    ++dist;
  }

  int n{(int)unique.size()};
  vector<vector<int>> adj(n, vector<int>(n));
  for (int i{0}; i < (int)s.size() - 1; ++i) {
    ++adj[um[s[i]]][um[s[i + 1]]];
  }

  vector<int> dp(1<<n, INT_MAX);
  dp[(1<<n)-1] = 1;
  for (int i{(1<<n)-1}; i >= 0; --i) {
    int b{i};
    while (b) {
      int sm{0};
      for (int j{0}; j < n; ++j) {
        if (!(i&(1<<j)) || (1<<j) == LSOne(b)) {
          sm += adj[__builtin_ctz(b)][j];
        }
      }
      dp[i^LSOne(b)] = min(dp[i^LSOne(b)], dp[i] + sm);
      b -= LSOne(b);
    }
  }

  cout << dp[0] << "\n";

  return 0;
}
