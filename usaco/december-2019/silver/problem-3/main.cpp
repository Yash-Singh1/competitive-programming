#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("milkvisits.in", "r", stdin);
  freopen("milkvisits.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  char a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> g[n];
  int x, y;
  for (int i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  bool visited[n];
  int comps{0};
  int comp[n];
  char compc[n];
  memset(comp, -1, n);
  memset(visited, 0, n);
  for (int i{0}; i < n; ++i) {
    if (visited[i]) continue;
    stack<int> s;
    s.push(i);
    compc[comps] = a[i];
    while (!s.empty()) {
      int stop{s.top()};
      s.pop();
      visited[stop] = 1;
      comp[stop] = comps;
      for (auto &ne: g[stop]) {
        if (!visited[ne] && a[ne] == a[i]) {
          s.push(ne);
        }
      }
    }
    ++comps;
  }

  char z;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    if ((comp[x] == comp[y] && z == compc[comp[x]]) || (comp[x] != comp[y])) {
      cout << 1;
    } else {
      cout << 0;
    }
  }

  cout << "\n";

  return 0;
}
