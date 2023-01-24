#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n, m;
  cin >> t;

  while (t--) {
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<int>> tg(n);
    int x, y;
    for (int i{0}; i < m; ++i) {
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      tg[y].push_back(x);
    }
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    queue<pii> q;
    q.push({0, 0});
    while (q.size()) {
      int u = q.front().first;
      int d = q.front().second;
      q.pop();
      if (dist[u] != d) continue;
      for (auto &v: g[u]) {
        if (d + 1 < dist[v]) {
          dist[v] = d + 1;
          q.push({v, d + 1});
        }
      }
    }
    vector<int> dp = dist;
    queue<int> q2;
    for (int i{0}; i < n; ++i) {
      for (auto &v: tg[i]) {
        if (dist[i] < dist[v]) {
          dp[v] = min(dp[v], dist[i]);
        }
      }
      q2.push(i);
    }
    while (q2.size()) {
      int u = q2.front();
      q2.pop();
      for (auto &v: tg[u]) {
        if (dist[u] > dist[v] && dp[u] < dp[v]) {
          dp[v] = dp[u];
          q2.push(v);
        }
      }
    }
    for (int i{0}; i < n; ++i) cout << dp[i] << " ";
    cout << "\n";
  }

  return 0;
}
