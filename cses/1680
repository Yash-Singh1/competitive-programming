#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  vector<vector<int>> tg(n);
  vector<int> indeg(n);
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    tg[y].push_back(x);
    ++indeg[y];
  }

  vector<int> dp(n, -1);
  dp[0] = 1;
  vector<int> p(n, -1);
  queue<int> q;
  for (int i{n - 1}; i >= 0; --i) {
    if (!indeg[i]) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v: g[u]) {
      --indeg[v];
      if (!indeg[v]) {
        q.push(v);
      }
    }
    for (auto &v: tg[u]) {
      if (dp[v] != -1 && dp[v] + 1 > dp[u]) {
        dp[u] = dp[v] + 1;
        p[u] = v;
      }
    }
  }

  if (dp[n - 1] <= 0) {
    cout << "IMPOSSIBLE\n";
  } else {
    vector<int> ans(dp[n - 1]);
    cout << dp[n - 1] << "\n";
    int cur{n - 1};
    int j{0};
    while (cur != -1) {
      ans[dp[n - 1] - 1 - j] = cur+1;
      ++j;
      cur = p[cur];
    }
    for (auto &ansp: ans) cout << ansp << " ";
    cout << "\n";
  }

  return 0;
}
