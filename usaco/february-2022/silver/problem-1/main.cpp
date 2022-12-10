#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("redistribute.in", "r", stdin);
  // freopen("redistribute.out", "w", stdout);

  int n;
  cin >> n;

  int a[n][n];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  vector<int> g[n];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (a[i][j] == i+1) break;
      g[i].push_back(a[i][j] - 1);
    }
  }

  vector<int> g2[n];
  for (int i{0}; i < n; ++i) {
    for (auto &ne: g[i]) {
      g2[ne].push_back(i);
    }
  }

  bool visited[n];
  for (int i{0}; i < n; ++i) {
    stack<int> s;
    s.push(i);
    for (int i{0}; i < n; ++i) {
      visited[i] = 0;
    }
    while (!s.empty()) {
      int stop{s.top()};
      s.pop();
      if (visited[stop]) continue;
      visited[stop] = 1;
      for (auto &ne: g2[stop]) {
        if (!visited[ne]) s.push(ne);
      }
    }
    for (int j{0}; j < n; ++j) {
      if (visited[a[i][j] - 1]) {
        cout << a[i][j] << "\n";
        break;
      }
    }
  }

  return 0;
}
