#include <bits/stdc++.h>

using namespace std;

int ans[200000];
vector<int> g[200000];

int dfs(int i) {
  int sm{0};
  for (auto &ne: g[i]) {
    sm += dfs(ne);
  }
  ans[i] = sm;
  return sm + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n;
  for (int i{1}; i < n; ++i) {
    cin >> x;
    --x;
    g[x].push_back(i);
  }

  dfs(0);

  for (int i{0}; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}
