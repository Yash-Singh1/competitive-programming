#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> ans(n);
  vector<int> outdeg(n);
  vector<vector<int>> g(n);
  vector<vector<int>> tg(n);
  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    tg[y].push_back(x);
    ++outdeg[x];
  }

  priority_queue<int> q;
  for (int i{0}; i < n; ++i) {
    if (!outdeg[i]) q.push(i);
  }
  int j{0};
  while (!q.empty()) {
    int u = q.top();
    q.pop();
    for (auto &v: tg[u]) {
      --outdeg[v];
      if (!outdeg[v]) q.push(v);
    }
    ans[j++] = u + 1;
  }

  reverse(ans.begin(), ans.end());
  for (auto &ansp: ans) {
    cout << ansp << " ";
  }
  cout << "\n";

  return 0;
}
