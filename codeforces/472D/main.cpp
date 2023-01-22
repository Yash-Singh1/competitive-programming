// Find MST graph using Prim's Dense Alg
// Ensure all weights >0
// Run DFS on each node to check dist
// WA past test 9 but main thing works

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<vector<ll>> adj(n, vector<ll>(n));
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j < n; ++j) {
      cin >> adj[i][j];
    }
  }

  for (ll i{0}; i < n; ++i) {
    if (adj[i][i] != 0) {
      cout << "NO\n";
      return 0;
    }
    for (ll j{0}; j < n; ++j) {
      if (adj[i][j] != adj[j][i] || (i != j && adj[i][j] == 0)) {
        cout << "NO\n";
        return 0;
      }
    }
  }

  vector<bool> selected(n, 0);
  vector<pll> medge(n, {LLONG_MAX, -1});
  medge[0].first = 0;
  vector<vector<pll>> g(n);
  for (ll i{0}; i < n; ++i) {
    ll u = -1;
    for (ll j{0}; j < n; ++j) {
      if (!selected[j] && (u == - 1 || medge[j] < medge[u])) u = j;
    }
    if (medge[u].first == LLONG_MAX) {
      cout << "NO\n"; return 0;
    }
    selected[u] = 1;
    if (medge[u].second != -1) {
      g[medge[u].second].push_back({u, medge[u].first});
      g[u].push_back({medge[u].second, medge[u].first});
    }
    for (ll j{0}; j < n; ++j) {
      if (j != i && adj[u][j] < medge[j].first) {
        medge[j] = {adj[u][j], u};
      }
    }
  }

  for (ll i{0}; i < n; ++i) {
    vector<bool> visited(n);
    vector<ll> dist(n, LLONG_MAX);
    stack<pll> s;
    s.push({i, -1});
    dist[i] = 0;
    while (s.size()) {
      ll u = s.top().first;
      ll p = s.top().second;
      s.pop();
      if (visited[u]) continue;
      visited[u] = 1;
      if (dist[u] != adj[i][u]) {
        cout << "NO\n";
        return 0;
      }
      for (auto &v: g[u]) {
        if (v.first == p) continue;
        if (!visited[v.first]) {
          dist[v.first] = dist[u] + v.second;
          s.push({v.first, u});
        }
      }
    }
  }

  cout << "YES\n";

  return 0;
}
