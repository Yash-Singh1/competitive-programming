#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  vector<vector<vector<int>>> w(2, vector<vector<int>>(n));
  vector<vector<int>> tg(n);
  vector<vector<vector<int>>> tw(2, vector<vector<int>>(n));
  int x, y, z, q;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z >> q;
    --x; --y;
    g[x].push_back(y);
    tg[y].push_back(x);
    w[0][x].push_back(z);
    w[1][x].push_back(q);
    tw[0][y].push_back(z);
    tw[1][y].push_back(q);
  }

  vector<vector<int>> dist(2, vector<int>(n, INT_MAX));
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<vector<set<pii>>> bkk(2, vector<set<pii>>(n));
  for (int i{0}; i < 2; ++i) {
    dist[i][n-1] = 0;
    pq.push({0, n-1});
    while (pq.size()) {
      int d = pq.top().first;
      int u = pq.top().second;
      pq.pop();
      if (d != dist[i][u]) continue;
      for (int k{0}; k < (int)tg[u].size(); ++k) {
        if (d + tw[i][u][k] < dist[i][tg[u][k]]) {
          dist[i][tg[u][k]] = d + tw[i][u][k];
          bkk[i][tg[u][k]].clear();
          pq.push({dist[i][tg[u][k]], tg[u][k]});
        }
        if (d + tw[i][u][k] == dist[i][tg[u][k]]) {
          bkk[i][tg[u][k]].insert({tw[i][u][k], u});
        }
      }
    }
  }

  vector<int> fdist(n, INT_MAX);
  fdist[0] = 0;
  pq.push({0, 0});
  while (pq.size()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (d != fdist[u]) continue;
    for (int k{0}; k < (int)g[u].size(); ++k) {
      int ww{0};
      for (int ll{0}; ll < 2; ++ll) {
        if (bkk[ll][u].find({w[ll][u][k], g[u][k]}) == bkk[ll][u].end()) {
          ++ww;
        }
      }
      if (fdist[u] + ww < fdist[g[u][k]]) {
        fdist[g[u][k]] = fdist[u] + ww;
        pq.push({fdist[g[u][k]], g[u][k]});
      }
    }
  }

  cout << fdist[n-1] << '\n';

  return 0;
}
