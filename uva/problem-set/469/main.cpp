#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    string a;
    vector<string> grid;
    int x, y;
    bool f{1};
    while (getline(cin, a)) {
      if (a.empty()) continue;
      if (a[0] >= '0' && a[0] <= '9') {
        break;
      } else {
        grid.push_back(a);
      }
    }
    pair<int,int> comp[grid.size()][grid[0].size()];
    int tot_area[grid.size()][grid[0].size()];
    bool visited[grid.size()][grid[0].size()];
    for (int i{0}; i < grid.size(); ++i) {
      for (int j{0}; j < grid[0].size(); ++j) {
        visited[i][j] = 0;
      }
    }
    for (int i{0}; i < grid.size(); ++i) {
      for (int j{0}; j < grid[0].size(); ++j) {
        if (visited[i][j] || grid[i][j] != 'W') continue;
        stack<pair<int,int>> s;
        s.push({i,j});
        int area{0};
        while (!s.empty()) {
          pair<int,int> stop{s.top()};
          s.pop();
          if (visited[stop.first][stop.second]) continue;
          ++area;
          visited[stop.first][stop.second] = 1;
          comp[stop.first][stop.second] = {i,j};
          for (int k{-1}; k <= 1; ++k) {
            for (int l{-1}; l <= 1; ++l) {
              if (!(stop.first + k < 0 || stop.first + k >= grid.size() || stop.second + l < 0 || stop.second + l >= grid[0].size()) && !visited[stop.first + k][stop.second + l] && grid[stop.first + k][stop.second + l] == 'W') {
                s.push({stop.first + k, stop.second + l});
              }
            }
          }
        }
        // cout << "\n";
        // cout << area << "\n";
        tot_area[i][j] = area;
      }
    }
    // for (int i{0}; i < grid.size(); ++i) {
    //   for (int j{0}; j < grid[0].size(); ++j) {
    //     cout << tot_area[comp[i][j].first][comp[i][j].second] << " ";
    //   }
    //   cout << "\n";
    // }
    while ((f || getline(cin, a))) {
      stringstream ss;
      ss << a;
      ss >> x >> y;
      // cout << x << " " << y << "\n";
      --x; --y;
      cout << tot_area[comp[x][y].first][comp[x][y].second] << "\n";
      f = 0;
      char c = cin.get();
      if (c == '\n') c = cin.get();
      if (!(c >= '0' && c <= '9')) {
        cin.unget();
        break;
      }
      cin.unget();
    }
    if (t != 0) cout << "\n";
  }

  return 0;
}
