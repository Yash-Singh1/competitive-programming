#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // We can run a BFS with "infection"

  int n, m;
  cin >> n >> m;

  vector<vector<char>> mp(n, vector<char>(m));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> mp[i][j];
    }
  }

  vector<pii> movement;
  movement.push_back({0, -1});
  movement.push_back({0, 1});
  movement.push_back({1, 0});
  movement.push_back({-1, 0});

  queue<pair<pii,bool>> q;
  vector<vector<bool>> infected(n, vector<bool>(m));
  pii a;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      if (mp[i][j] == 'M') {
        q.push({{i, j}, 0});
      } else if (mp[i][j] == 'A') {
        a = {i,j};
      }
    }
  }
  // 1: uninfected
  q.push({a, 1});

  vector<vector<bool>> visited(n, vector<bool>(m));
  vector<vector<pair<pii,char>>> retrace(n, vector<pair<pii,char>>(m));
  pii ans{-1, -1};
  map<pii, char> mvback;
  mvback[{0, 1}] = 'R';
  mvback[{0, -1}] = 'L';
  mvback[{1, 0}] = 'D';
  mvback[{-1, 0}] = 'U';
  while (q.size()) {
    int x = q.front().first.first;
    int y = q.front().first.second;
    bool me = q.front().second;
    q.pop();
    if (me && (visited[x][y] || infected[x][y])) continue;
    if (me) visited[x][y] = 1;
    if (!me && infected[x][y]) continue;
    if (!me) infected[x][y] = 1;
    if ((x == 0 || x == n - 1 || y == 0 || y == m - 1) && me) {
      ans = {x, y};
      break;
    }
    for (auto &mv: movement) {
      if (mv.first + x < 0 || mv.first + x >= n || mv.second + y < 0 || mv.second + y >= m) continue;
      if (mp[x + mv.first][y + mv.second] != '.') continue;
      if (me && (infected[mv.first + x][mv.second + y] || visited[mv.first + x][mv.second + y])) continue;
      if (!me && infected[mv.first + x][mv.second + y]) continue;
      if (me) retrace[x + mv.first][y + mv.second] = {{x, y}, mvback[mv]};
      q.push({{x + mv.first, y + mv.second}, me});
    }
  }

  if (ans.first == -1) {
    cout << "NO\n";
    return 0;
  }

  vector<char> path;
  while (ans != a) {
    path.push_back(retrace[ans.first][ans.second].second);
    ans = retrace[ans.first][ans.second].first;
  }

  reverse(path.begin(), path.end());
  cout << "YES\n" << path.size() << "\n";
  for (auto &p: path) {
    cout << p;
  }
  cout << "\n";

  return 0;
}
