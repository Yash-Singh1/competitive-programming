// Has some strict bipartite coloring possibility validation, so like 1/2 of the TCs fail

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a[n + 1];
  for (int i{0}; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  int c[n + 1];
  for (int i{1}; i <= n; ++i) {
    c[i] = -1;
  }
  for (int i{1}; i <= n; ++i) {
    int cur{-1};
    for (auto fr: a[i]) {
        if (c[fr] != -1 && cur != -1 && c[fr] == cur) {
            cout << "IMPOSSIBLE";
            return 0;
        } else if (c[fr] != -1 && cur == -1) {
            cur = 3 - c[fr];
        }
    }
    if (cur == -1) {
        c[i] = 1;
    } else {
        c[i] = cur;
    }
  }
  for (int i{1}; i <= n; ++i) {
    cout << c[i] << " ";
  }
}
