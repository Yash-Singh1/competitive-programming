#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  ll a, b;
  cin >> n >> a >> b;

  vector<vector<char>> grid(n, vector<char>(n));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<vector<pii>> g(n*n);
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (i) {
        g[i*n+j].push_back({(i-1)*n+j, grid[i][j] == grid[i-1][j] ? a : b});
      }
      if (j) {
        g[i*n+j].push_back({i*n+j-1, grid[i][j] == grid[i][j-1] ? a : b});
      }
      if (i < n-1) {
        g[i*n+j].push_back({(i+1)*n+j, grid[i][j] == grid[i+1][j] ? a : b});
      }
      if (j < n-1) {
        g[i*n+j].push_back({i*n+j+1, grid[i][j] == grid[i][j+1] ? a : b});
      }
    }
  }

  priority_queue<pli, vector<pli>, greater<pli>> pq;
  vector<ll> dist(n*n);
  ll ans{0};
  for (int i{0}; i < n*n; ++i) {
    for (int j{0}; j < n*n; ++j) {
      dist[j] = LLONG_MAX;
    }
    dist[i] = 0;
    pq.push({0, i});
    while (pq.size()) {
      ll d = pq.top().first;
      int u = pq.top().second;
      pq.pop();
      if (d != dist[u]) continue;
      for (auto &v: g[u]) {
        if (v.second + d < dist[v.first]) {
          dist[v.first] = v.second + d;
          pq.push({dist[v.first], v.first});
        }
      }
    }
    for (int j{0}; j < n*n; ++j) {
      if (dist[j] == LLONG_MAX) continue;
      ans = max(ans, dist[j]);
    }
  }

  cout << ans << '\n';

  return 0;
}
