#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;

struct State {
  int x, y, dir;
  int orange;
  bool operator<(const State &o)  const {
    if (x == o.x) {
      if (y == o.y) {
        if (dir == o.dir) {
          return orange < o.orange;
        }
        return dir < o.dir;
      }
      return y < o.y;
    }
    return x < o.x;
  }
};

unordered_map<int, int> dist;

int n, m;

int hashst(State state) {
  return state.dir * 2 + state.orange + state.x * (2 * 4) + state.y * (2 * 4 * (n - 1) * (m - 1));
}

bool setstate(State state, int d) {
  int hs{hashst(state)};
  auto it = dist.find(hs);
  if (it == dist.end()) {
    dist[hs] = d;
    return 1;
  }
  return 0;
}

int getstate(int state) {
  return dist[state];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("dream.in", "r", stdin);
  freopen("dream.out", "w", stdout);

  // we store bfs state with (x, y) and direction and smells_like_oranges
  // runs in O(n*m*4*2) which is less than TLE

  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  queue<State> q;
  State start;
  start.x = 0; start.y = 0; start.dir = 0; start.orange = 0;
  q.push(start);
  setstate(start, 0);

  int dx[4] {-1, 0, 1, 0};
  int dy[4] {0, 1, 0, -1};
  while (q.size()) {
    State u = q.front();
    int hs{hashst(u)};
    if (u.x == n-1 && u.y == m-1) {
      cout << getstate(hs) << '\n';
      return 0;
    }
    q.pop();
    State other = u;
    for (int i{0}; i < 4; ++i) {
      other.dir = i;
      if (setstate(other, getstate(hs))) {
        q.push(other);
      }
      other = u;
    }
    if (u.x + dx[u.dir] >= 0 && u.x + dx[u.dir] < n && u.y + dy[u.dir] >= 0 && u.y + dy[u.dir] < m) {
      int nx = grid[u.x + dx[u.dir]][u.y + dy[u.dir]];
      int extra{1};
      if (nx == 0) {
        continue;
      } else if (nx == 1) {
        other.x += dx[u.dir];
        other.y += dy[u.dir];
      } else if (nx == 2) {
        other.x += dx[u.dir];
        other.y += dy[u.dir];
        other.orange = 1;
      } else if (nx == 3) {
        if (u.orange) {
          other.x += dx[u.dir];
          other.y += dy[u.dir];
        } else {
          continue;
        }
      } else if (nx == 4) {
        other.x += dx[u.dir];
        other.y += dy[u.dir];
        other.orange = 0;
        if (other.x + dx[u.dir] >= 0 && other.x + dx[u.dir] < n && other.y + dy[u.dir] >= 0 && other.y + dy[u.dir] < m) {
          other.x += dx[u.dir];
          other.y += dy[u.dir];
          ++extra;
        }
      }
      if (setstate(other, getstate(hs) + extra)) {
        q.push(other);
      }
    }
  }

  cout << -1 << '\n';

  return 0;
}
