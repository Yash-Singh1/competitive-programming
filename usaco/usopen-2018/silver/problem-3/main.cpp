// TLE on one test case, but I can't make better optimizations.

#include <bits/stdc++.h>

using namespace std;

int dx[4] {0, 0, 1, -1};
int dy[4] {1, -1, 0, 0};

inline void sort_pair(pair<int,int> &a) {
  if (a.first > a.second) {
    int s{a.second};
    a.second = a.first;
    a.second = s;
  }
}

struct PairHash {
  auto operator()(const pair<int, int> &p) const -> size_t {
    return (p.first<<16)+p.second;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("multimoo.in", "r", stdin);
  freopen("multimoo.out", "w", stdout);

  int n;
  cin >> n;

  int a[n][n];
  bool visited[n][n];
  int comps[n][n];
  for (int i{0}; i <n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> a[i][j];
      visited[i][j] = 0;
    }
  }

  int regions{0};
  pair<int,int> regionp[n*n];
  int area[n*n];
  int farea{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (visited[i][j]) continue;
      stack<pair<int,int>> s;
      regionp[regions] = {i,j};
      area[regions] = 0;
      s.push({i,j});
      while (!s.empty()) {
        pair<int,int> stop{s.top()};
        s.pop();
        if (visited[stop.first][stop.second]) continue;
        ++area[regions];
        visited[stop.first][stop.second] = 1;
        comps[stop.first][stop.second] = regions;
        for (int k{0}; k < 4; ++k) {
          if (stop.first + dx[k] < 0 || stop.first + dx[k] >= n) continue;
          if (stop.second + dy[k] < 0 || stop.second + dy[k] >= n) continue;
          if (visited[stop.first + dx[k]][stop.second + dy[k]]) continue;
          if (a[stop.first + dx[k]][stop.second + dy[k]] != a[i][j]) continue;
          s.push({stop.first + dx[k], stop.second + dy[k]});
        }
      }
      farea = max(area[regions], farea);
      ++regions;
    }
  }

  cout << farea << "\n";

  unordered_set<int> g[regions];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      for (int k{0}; k < 4; ++k) {
        if (i + dx[k] < 0 || i + dx[k] >= n) continue;
        if (j + dy[k] < 0 || j + dy[k] >= n) continue;
        if (a[i + dx[k]][j + dy[k]] != a[i][j]) {
          g[comps[i][j]].insert(comps[i + dx[k]][j + dy[k]]);
        }
      }
    }
  }

  // for (int i{0}; i < regions; ++i) {
  //   cout << a[regionp[i].first][regionp[i].second] << " ";
  //   for (auto &ne: g[i]) {
  //     cout << a[regionp[ne].first][regionp[ne].second] << " ";
  //   }
  //   cout << "\n";
  // }

  bool visitedo[regions];
  int mans{0};
  unordered_set<pair<int,int>, PairHash> calculated;
  for (int i{0}; i < regions; ++i) {
    for (auto j = g[i].begin(); j != g[i].end(); j = next(j)) {
      if (i > *j) continue;
      pair<int,int> regionreality{i, *j};
      sort_pair(regionreality);
      if (calculated.find(regionreality) != calculated.end()) {
        continue;
      }
      calculated.insert(regionreality);
      memset(visitedo, 0, sizeof(visitedo));
      stack<int> s;
      s.push(i);
      int ans{0};
      while (!s.empty()) {
        int stop{s.top()};
        s.pop();
        if (visitedo[stop]) continue;
        ans += area[stop];
        visitedo[stop] = 1;
        for (auto &ne: g[stop]) {
          if (visitedo[ne]) continue;
          if (a[regionp[ne].first][regionp[ne].second] == a[regionp[i].first][regionp[i].second] || a[regionp[ne].first][regionp[ne].second] == a[regionp[*j].first][regionp[*j].second]) {
            pair<int,int> regionreality2{stop, ne};
            sort_pair(regionreality2);
            calculated.insert(regionreality2);
            s.push(ne);
          }
        }
      }
      // if (ans > mans) cout << a[regionp[i].first][regionp[i].second] << " " << a[regionp[g[i][*j]].first][regionp[g[i][*j]].second] << "\n";
      mans = max(ans, mans);
    }
  }

  cout << mans << "\n";

  return 0;
}
