#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, f, s;
  cin >> n >> m >> f >> s;
  --f; --s;
  vector<vector<int>> g(n);
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y; --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  stack<int> st;
  st.push(f);
  vector<bool> visited(n);
  vector<int> prev(n, -1);
  prev[f] = f;
  while (st.size()) {
    int tp{st.top()};
    st.pop();
    visited[tp] = 1;
    for (auto &ne: g[tp]) {
      if (prev[ne] == -1) {
        prev[ne] = tp;
        st.push(ne);
      }
    }
    if (prev[s] != -1) {
      break;
    }
  }

  vector<int> bk;
  int cur{s};
  while (cur != f) {
    bk.push_back(cur);
    cur = prev[cur];
  }
  bk.push_back(f);
  reverse(bk.begin(), bk.end());

  cout << bk.size() << '\n';
  for (auto &pt: bk) {
    cout << pt+1 << '\n';
  }

  return 0;
}
