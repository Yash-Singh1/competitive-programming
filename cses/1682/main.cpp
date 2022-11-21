#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> g[n];
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
  }

  vector<int> g2[n];
  bool visited[n];
  for (int j{0}; j < 2; ++j) {
    if (j == 1) {
      for (int i{0}; i < n; ++i) {
        for (auto &ne: g[i]) {
          g2[ne].push_back(i);
        }
      }
    }
    stack<int> s;
    s.push(0);
    for (int i{0}; i < n; ++i) {
      visited[i] = 0;
    }
    while (!s.empty()) {
      int stop{s.top()};
      s.pop();
      visited[stop] = 1;
      for (auto &ne: (j == 1 ? g2 : g)[stop]) {
        if(!visited[ne]) s.push(ne);
      }
    }
    for (int i{0}; i < n; ++i) {
      if (!visited[i]) {
        cout << "NO\n" << (j==1 ? i+1 : 1) << " " << (j == 1 ? 1 : i+1) << "\n";
        return 0;
      }
    }
  }

  cout << "YES\n";

  return 0;
}
