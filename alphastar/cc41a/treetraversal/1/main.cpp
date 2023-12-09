#include <bits/stdc++.h>

using namespace std;

vector<int> mh;
vector<vector<int>> g;
void dfs(int u, int p) {
  if (g[u].size() == 1) {
    mh[u] = 0;
  }
  for (auto &v: g[u]) {
    if (v != p) {
      dfs(v, u);
      mh[u] = min(mh[v] + 1, mh[u]);
    }
  }
}

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  --k;
  g.resize(n);

  int x, y;
  for (int i{0}; i < n-1; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  mh = vector<int>(n, INT_MAX);
  dfs(k, -1);
  stack<pii> s;
  vector<int> d(n);
  s.push({k, -1});
  int mreq{0};
  while (s.size()) {
    int u = s.top().first;
    int p = s.top().second;
    s.pop();
    if (p >= 0) d[u] = d[p] + 1;
    if (mh[u] <= d[u]) {
      ++mreq;
    } else {
      for (auto &v: g[u]) {
        if (v != p) {
          s.push({v, u});
        }
      }
    }
  }

  cout << mreq << '\n';

  return 0;
}
