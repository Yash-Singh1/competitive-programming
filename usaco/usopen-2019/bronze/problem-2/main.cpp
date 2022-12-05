#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("factory.in", "r", stdin);
  freopen("factory.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> g[n];
  int x, y;
  for (int i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[y].push_back(x);
  }

  bool visited[n];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) visited[j] = 0;
    stack<int> s;
    s.push(i);
    while (!s.empty()) {
      int stop{s.top()};
      s.pop();
      visited[stop] = 1;
      for (auto &ne: g[stop]) {
        if (!visited[ne]) {
          s.push(ne);
        }
      }
    }
    bool fail{0};
    for (int j{0}; j < n; ++j) {
      if (!visited[j]) {
        fail = 1;
        break;
      }
    }
    if (!fail) {
      cout << i+1 << "\n";
      return 0;
    }
  }

  cout << -1 << "\n";

  return 0;
}
