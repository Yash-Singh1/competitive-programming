#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int val[n];
  char x;
  for (int i{0}; i < n; ++i) {
    cin >> x; val[i] = x - 'a';
  }

  int a, b;
  vector<vector<int>> g(n);
  vector<int> in(n);
  for (int i{0}; i < m; ++i) {
    cin >> a >> b; --a; --b;
    g[a].push_back(b);
    ++in[b];
  }

  stack<int> s;
  vector<vector<int>> dp(n, vector<int>(26));
  bool one{0};
  for (int i{0}; i < n; ++i) {
    if (!in[i]) {
      s.push(i);
      one = 1;
      dp[i][val[i]] = 1;
    }
  }

  // vector<bool> visited(n);
  // stack<int> c;
  // for (int i{0}; i < n; ++i) {
  //   if (visited[i]) continue;
  //   c.push(i);
  //   while (c.size()) {
  //     int u = c.top();
  //     c.pop();
  //     if (visited[u]) {
  //       cout << u << " " << "-1\n";
  //       return 0;
  //     }
  //     visited[u] = 1;
  //     for (auto &v: g[u]) {
  //       c.push(v);
  //     }
  //   }
  // }

  while (s.size()) {
    int u = s.top();
    s.pop();
    for (auto &v: g[u]) {
      --in[v];
      if (in[v] < 0) {
        cout << "-1\n";
        return 0;
      }
      for (int i{0}; i < 26; ++i) {
        dp[v][i] = max(dp[v][i], dp[u][i] + (val[v] == i ? 1 : 0));
      }
      if (!in[v]) s.push(v);
    }
  }

  for (int i{0}; i < n; ++i) {
    if (in[i]) {
      cout << "-1\n";
      return 0;
    }
  }

  int ans{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < 26; ++j) {
      ans = max(dp[i][j], ans);
    }
  }

  cout << ans << "\n";

  return 0;
}
