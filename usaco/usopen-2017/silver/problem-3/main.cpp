#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int dx[4] {0, 0, 1, -1};
int dy[4] {1, -1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("where.in", "r", stdin);
  freopen("where.out", "w", stdout);

  int n;
  cin >> n;

  char a[n][n];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  pii comps[n][n];
  bool visited[n][n];
  bool conq[n][n];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      visited[i][j] = 0;
      conq[i][j] = 0;
    }
  }

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (visited[i][j]) continue;
      stack<pii> s;
      s.push({i,j});
      while (!s.empty()) {
        pii stop{s.top()};
        s.pop();
        if (visited[stop.first][stop.second]) continue;
        visited[stop.first][stop.second] = 1;
        comps[stop.first][stop.second] = {i,j};
        for (int k{0}; k < 4; ++k) {
          if (stop.first + dx[k] < 0 || stop.first + dx[k] >= n) continue;
          if (stop.second + dy[k] < 0 || stop.second + dy[k] >= n) continue;
          if (visited[stop.first + dx[k]][stop.second + dy[k]]) continue;
          if (a[i][j] != a[stop.first + dx[k]][stop.second + dy[k]]) continue;
          s.push({stop.first + dx[k], stop.second + dy[k]});
        }
      }
    }
  }

  map<char,int> components_set;
	set<pii> compse;
  int pcls{0};
  pair<pii,pii> pclWinners[n*n*n*n];
  for (int k{0}; k < n; ++k) {
    for (int l{0}; l < n; ++l) {
      for (int i{k}; i < n; ++i) {
        for (int j{l}; j < n; ++j) {
          if (k == i && l == j) continue;
          compse.clear();
          components_set.clear();
          for (int x{k}; x <= i; ++x) {
            for (int y{l}; y <= j; ++y) {
              visited[x][y] = 0;
            }
          }
          for (int x{k}; x <= i; ++x) {
            for (int y{l}; y <= j; ++y) {
              if (visited[x][y]) continue;
              stack<pii> s;
              s.push({x,y});
              while (!s.empty()) {
                pii stop{s.top()};
                s.pop();
                if (visited[stop.first][stop.second]) continue;
                visited[stop.first][stop.second] = 1;
                for (int u{0}; u < 4; ++u) {
                  if (stop.first + dx[u] < k || stop.first + dx[u] > i) continue;
                  if (stop.second + dy[u] < l || stop.second + dy[u] > j) continue;
                  if (visited[stop.first + dx[u]][stop.second + dy[u]]) continue;
                  if (a[stop.first + dx[u]][stop.second + dy[u]] != a[x][y]) continue;
                  s.push({stop.first + dx[u], stop.second + dy[u]});
                }
              }
              ++components_set[a[x][y]];
            }
          }
          // cout << components_set.size() << " " << components_set.rbegin()->second << " " << components_set.begin()->second << "\n";
          // // need to redo floodfill for each rectangle
          // for (int x{k}; x <= i; ++x) {
          //   for (int y{l}; y <= j; ++y) {
          //     // if (conq[x][y]) goto end;
          //     if (compse.find(comps[x][y]) == compse.end()) {
          //       if (components_set.find(a[x][y]) == components_set.end()) components_set[a[x][y]] = 0;
          //       ++components_set[a[x][y]];
          //       compse.insert(comps[x][y]);
          //     }
          //     if (components_set.size() > 2) goto end;
          //   }
          // }
          if (components_set.size() == 2 && ((components_set.rbegin()->second == 1 && components_set.begin()->second >= 2) || (components_set.begin()->second == 1 && components_set.rbegin()->second >= 2))) {
            // for (int x{k}; x <= i; ++x) {
            //   for (int y{l}; y <= j; ++y) {
            //     conq[x][y] = 1;
            //   }
            // }
            // cout << "B" << k << " " << l << " - " << i << " " << j << "\n";
            pclWinners[pcls] = {{k, l}, {i, j}};
            ++pcls;
          }
        }
			}
    }
  }

  bool val[pcls];
  for (int i{0}; i < pcls; ++i) val[i] =1;
  for (int i{0}; i < pcls; ++i) {
    if (!val[i]) continue;
    for (int x{0}; x < pcls; ++x) {
      if (!val[x]) continue;
      if (i == x) continue;
      // cout << k << " " << l << " - " << i << " " << j << " : " << pclWinners[x].first.first << " " << pclWinners[x].first.second << " - " << pclWinners[x].second.first << " " << pclWinners[x].second.second << "\n";
      if (pclWinners[i].first.first >= pclWinners[x].first.first && pclWinners[i].first.second >= pclWinners[x].first.second && pclWinners[i].second.first <= pclWinners[x].second.first && pclWinners[i].second.second <= pclWinners[x].second.second) {
        val[i] = 0;
        goto endThis;
      }
    }
    endThis: continue;
  }
  int opcls = 0;
  for (int i{0}; i < pcls; ++i) {
    if (val[i]) {
      // cout << "A" << pclWinners[i].first.first << " " << pclWinners[i].first.second << " - " << pclWinners[i].second.first << " " << pclWinners[i].second.second << "\n";
      ++opcls;
    }
  }

  cout << opcls << "\n";

  return 0;
}
