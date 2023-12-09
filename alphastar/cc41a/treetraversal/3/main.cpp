#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
int t{0};
vector<int> ans, h;
int mh{0};

typedef long long ll;

void dfs(int u, int d) {
  mh = max(mh, d);
  h[u] = d;
  for (auto &v: g[u]) {
    dfs(v, d+1);
  }
  ans[u] = t;
  ++t;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> j(n);
  g.resize(n+1); ans.resize(n+1); h.resize(n+1);
  for (int i{0}; i < n; ++i) {
    cin >> j[i];
    g[j[i]].push_back(i);
  }

  dfs(n, 0);

  cout << n+1 << '\n';
  for (int i{0}; i < n; ++i) {
    cout << (ll)ans[i] + (ll)(mh-h[i])*(n+1) << '\n';
  }

  return 0;
}
