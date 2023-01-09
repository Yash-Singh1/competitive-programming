#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<char>> g(n, vector<char>(m));
	pair<int,int> start, end;
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < m; ++j) {
			cin >> g[i][j];
			if (g[i][j] == 'A') {
				start = {i, j};
			} else if (g[i][j] == 'B') {
				end = {i, j};
			}
		}
	}

  int dx[4] {0, 0, 1, -1};
  int dy[4] {1, -1, 0, 0};
  char move[4] {'R', 'L', 'D', 'U'};
	queue<pair<int,int>> q;
	q.push(start);
  vector<vector<pair<int,int>>> dist(n, vector<pair<int,int>>(m, {INT_MAX, -1}));
	dist[start.first][start.second].first = 0;
  while (!q.empty()) {
    pair<int,int> qtop{q.front()};
    q.pop();
    for (int i{0}; i < 4; ++i) {
      if (qtop.first + dx[i] < 0 || qtop.first + dx[i] >= n || qtop.second + dy[i] < 0 || qtop.second + dy[i] >= m) continue;
      if (g[qtop.first + dx[i]][qtop.second + dy[i]] == '#') continue;
      if (dist[qtop.first + dx[i]][qtop.second + dy[i]].first == INT_MAX) {
        dist[qtop.first + dx[i]][qtop.second + dy[i]] = {dist[qtop.first][qtop.second].first + 1, i};
        q.push({qtop.first + dx[i], qtop.second + dy[i]});
      }
    }
	}

  // for (int i{0}; i < n; ++i) {
  //   for (int j{0}; j < m; ++j) {
  //     cout << dist[i][j].first
  //   }
  // }

  if (dist[end.first][end.second].first == INT_MAX) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  cout << dist[end.first][end.second].first << "\n";
  pair<int,int> cur = end;
  vector<char> ans(dist[end.first][end.second].first);
  for (int i{dist[end.first][end.second].first - 1}; i >= 0; --i) {
    if (dist[cur.first][cur.second].second == -1) {
      break;
    } else {
      ans[i] = move[dist[cur.first][cur.second].second];
      cur = {cur.first - dx[dist[cur.first][cur.second].second], cur.second - dy[dist[cur.first][cur.second].second]};
    }
  }

  for (auto &ae: ans) {
    cout << ae;
  }
  cout << "\n";

  return 0;
}
