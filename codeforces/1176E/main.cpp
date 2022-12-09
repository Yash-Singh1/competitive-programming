#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n, m, x, y;
  cin >> t;

  while (t--) {
    cin >> n >> m;
    vector<int> g[n];
    for (int i{0}; i < m; ++i) {
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    int color[n];
    for (int i{0}; i < n; ++i) {
      color[i] = -1;
    }
    stack<int> s;
    s.push(0);
    color[0] = 1;
    while (!s.empty()) {
      int stop{s.top()};
      s.pop();
      for (auto &ne: g[stop]) {
        if (color[ne] == -1) {
          color[ne] = 3 - color[stop];
          s.push(ne);
        }
      }
    }
    int tot{0}, tot2{0};
    for (int i{0}; i < n; ++i) {
      if (color[i] == 2) ++tot;
      else ++tot2;
    }
    cout << min(tot, tot2) << "\n";
    for (int i{0}; i < n; ++i) {
      if (color[i] == (tot > tot2 ? 1 : 2)) {
        cout << i + 1 << " ";
      }
    }
    cout << "\n";
  }

  return 0;
}
