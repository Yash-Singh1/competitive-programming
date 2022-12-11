/*
ID: saiansh1
LANG: C++
TASK: castle
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int dx[4] {1, -1, 0, 0};
int dy[4] {0, 0, 1, -1};

map<pii, char> ddir{{{0, -1}, 'W'}, {{-1, 0}, 'N'}, {{0, 1}, 'E'}, {{1, 0}, 'S'}};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("castle.in", "r", stdin);
  freopen("castle.out", "w", stdout);

  int m, n;
  cin >> n >> m;

  set<pair<pii,pii>> disabled;
  int x;
  for (int i{0}; i < m; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> x;
      if (x & 1 && j) {
        disabled.insert({{i, j}, {i, j-1}});
      }
      if (x & 2 && i) {
        disabled.insert({{i, j}, {i-1, j}});
      }
      if (x & 4 && j != n-1) {
        disabled.insert({{i, j}, {i, j+1}});
      }
      if (x & 8 && i != m-1) {
        disabled.insert({{i, j}, {i+1, j}});
      }
    }
  }

  bool visited[m][n];
  for (int i{0}; i < m; ++i) {
    for (int j{0}; j < n; ++j) {
      visited[i][j] = 0;
    }
  }
  int rooms{0};
  int roommx{0};
  int area[n*m];
  int croom[m][n];
  for (int i{0}; i < m; ++i) {
    for (int j{0}; j < n; ++j) {
      if (visited[i][j]) continue;
      stack<pii> s;
      s.push({i,j});
      int sz{0};
      while (!s.empty()) {
        pii stop{s.top()};
        s.pop();
        if (visited[stop.first][stop.second]) {
          continue;
        }
        ++sz;
        visited[stop.first][stop.second] = 1;
        croom[stop.first][stop.second] = rooms;
        for (int k{0}; k < 4; ++k) {
          if (stop.first + dx[k] < 0 || stop.second + dy[k] < 0 || stop.first + dx[k] >= m || stop.second + dy[k] >= n) {
            continue;
          }
          if (visited[stop.first + dx[k]][stop.second + dy[k]] || disabled.find({stop, {stop.first + dx[k], stop.second + dy[k]}}) != disabled.end()) {
            continue;
          }
          s.push({stop.first + dx[k], stop.second + dy[k]});
        }
      }
      area[rooms] = sz;
      ++rooms;
      roommx = max(roommx, sz);
    }
  }

  cout << rooms << "\n" << roommx << "\n";

  int mcomb{-1};
  char mdir;
  pii mpos;
  for (auto it = disabled.begin(); it != disabled.end(); it = next(it)) {
    int ar{area[croom[it->first.first][it->first.second]]};
    if (croom[it->first.first][it->first.second] != croom[it->second.first][it->second.second]) {
      ar += area[croom[it->second.first][it->second.second]];
    }
    char dr{ddir[{it->second.first - it->first.first, it->second.second - it->first.second}]};
    if (ar > mcomb) {
      mcomb = ar;
      mdir = dr;
      mpos = it->first;
    } else if (ar == mcomb) {
      if (mpos.second > it->first.second) {
        mpos = it->first;
        mdir = dr;
      } else if (mpos.second == it->first.second) {
        if (mpos.first < it->first.first) {
          mpos = it->first;
          mdir = dr;
        } else if (mpos.first == it->first.first) {
          if (mdir == 'E' && dr == 'N') {
            mpos = it->first;
            mdir = dr;
          }
        }
      }
    }
  }

  cout << mcomb << "\n" << mpos.first+1 << " " << mpos.second+1 << " " << mdir << "\n";
}
