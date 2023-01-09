#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<pair<int,int>> dist(n, {INT_MAX-5, -1});
  dist[0].first = 0;
  queue<int> q;
  q.push(0);
  x = 1;
  while (!q.empty()) {
    int qtop{q.front()};
    q.pop();
    for (auto &ne: g[qtop]) {
      if (dist[ne].first == INT_MAX-5) {
        dist[ne] = {dist[qtop].first + 1, qtop};
        q.push(ne);
        if (ne == n-1) goto done;
      }
    }
  }

  if (x == 1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  done: x = 0;

  int cur{n-1};
  cout << dist[cur].first+1 << "\n";
  vector<int> path(dist[cur].first + 1);
  int j{dist[cur].first};
  while (cur != -1) {
    path[j] = cur;
    cur = dist[cur].second;
    --j;
  }

  for (auto &node: path) {
    cout << node+1 << " ";
  }
  cout << "\n";

  return 0;
}
