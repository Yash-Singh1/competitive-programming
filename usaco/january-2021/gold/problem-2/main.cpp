#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> t(n);
  for (int i{0}; i < n; ++i) {
    cin >> t[i];
    --t[i];
  }

  vector<vector<bool>> g(52, vector<bool>(52));
  char x;
  for (int i{0}; i < k; ++i) {
    for (int j{0}; j < k; ++j) {
      cin >> x;
      if (x == '1') {
        g[i][j] = 1;
        if (t[n - 1] == i) {
          g[k][j] = 1;
        }
        if (t[n - 1] == j) {
          g[i][k] = 1;
        }
      }
    }
  }
  t[n - 1] = k;

  deque<pii> q;
  vector<vector<int>> dist(n, vector<int>(52, INT_MAX));
  q.push_back({0, t[0]});
  dist[0][t[0]] = 0;
  while (q.size()) {
    int u = q.front().first;
    int b = q.front().second;
    q.pop_front();
    if (u && dist[u-1][b] == INT_MAX) {
      dist[u-1][b] = dist[u][b] + 1;
      q.push_back({u-1, b});
    }
    if (u < n - 1 && dist[u+1][b] == INT_MAX) {
      dist[u+1][b] = dist[u][b] + 1;
      q.push_back({u+1, b});
    }
    if (dist[u][t[u]] == INT_MAX && g[b][t[u]]) {
      dist[u][t[u]] = dist[u][b];
      // cout << u << " " << b << " " << t[u] << " " << dist[u][b] << "\n";
      q.push_front({u, t[u]});
    }
  }

  cout << (dist[n-1][t[n-1]]==INT_MAX?-1:dist[n-1][t[n-1]]) << "\n";

  return 0;
}
