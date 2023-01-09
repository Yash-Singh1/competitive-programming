#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<char>> g(n, vector<char>(m));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> g[i][j];
    }
  }

  // for (int i{0}; i < n; ++i) {
  //   for (int j{0}; j < m; ++j) {
  //     cout << g[i][j];
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  // find max distance from source node to any other node + 1 with nodes being connected components
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  vector<vector<int>> comp(n, vector<int>(m, -1));
  vector<int> dx = {0, 0, 1, -1};
  vector<int> dy = {1, -1, 0, 0};
  int curcomp{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      if (visited[i][j] || g[i][j] == '.') continue;
      queue<pii> q;
      q.push({i, j});
      while (!q.empty()) {
        pii qtop{q.front()};
        q.pop();
        if (visited[qtop.first][qtop.second]) continue;
        visited[qtop.first][qtop.second] = 1;
        comp[qtop.first][qtop.second] = curcomp;
        for (int k{0}; k < 4; ++k) {
          if (qtop.first + dx[k] < 0 || qtop.first + dx[k] >= n || qtop.second + dy[k] < 0 || qtop.second + dy[k] >= m || visited[qtop.first + dx[k]][qtop.second + dy[k]] || g[qtop.first + dx[k]][qtop.second + dy[k]] != g[i][j]) continue;
          q.push({qtop.first + dx[k], qtop.second + dy[k]});
        }
      }
      ++curcomp;
    }
  }

  // for (int i{0}; i < n; ++i) {
  //   for (int j{0}; j < m; ++j) {
  //     cout << comp[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  vector<unordered_set<int>> graph(n*m);
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      for (int k{0}; k < 4; ++k) {
        if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= m) continue;
        if (comp[i][j] == -1 || comp[i + dx[k]][j + dy[k]] == -1) continue;
        if (comp[i][j] != comp[i + dx[k]][j + dy[k]]) {
          graph[comp[i][j]].insert(comp[i + dx[k]][j + dy[k]]);
        }
      }
    }
  }

  vector<int> dist(curcomp, INT_MAX);
  dist[0] = 0;
  queue<int> q;
  q.push(0);
  int ans{0};
  while (!q.empty()) {
    int qtop{q.front()};
    q.pop();
    ans = max(ans, dist[qtop]);
    for (auto it = graph[qtop].begin(); it != graph[qtop].end(); it = next(it)) {
      if (dist[*it] != INT_MAX) continue;
      dist[*it] = dist[qtop] + 1;
      q.push(*it);
    }
  }

  cout << ans+1 << "\n";

  return 0;
}
