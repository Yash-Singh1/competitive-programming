#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> type;
vector<int> l;
vector<int> p;
vector<vector<int>> g;
vector<ll> f, dpin, dp;
ll ans = LLONG_MAX;

void dfsfile(int u) {
  for (auto &v: g[u]) {
    if (type[v]) {
      dfsfile(v);
      f[u] += f[v];
    } else {
      ++f[u];
    }
  }
}

void dfsin(int u) {
  for (auto &v: g[u]) {
    if (type[v]) {
      dfsin(v);
      dpin[u] += dpin[v] + (l[v] + 1) * f[v];
    } else {
      dpin[u] += l[v];
    }
  }
}

void dfsans(int u) {
  if (!u) {
    dp[u] = dpin[u];
  } else {
    dp[u] = dp[p[u]] - (l[u] + 1) * f[u] + 3 * (f[0] - f[u]);
  }
  ans = min(dp[u], ans);
  for (auto &v: g[u]) {
    if (type[v]) dfsans(v);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  type.resize(n); l.resize(n); p.resize(n); g.resize(n); f.resize(n);
  dpin.resize(n); dp.resize(n);
  string s;
  int x;
  for (int i{0}; i < n; ++i) {
    cin >> s;
    l[i] = s.size();
    cin >> type[i];
    for (int j{0}; j < type[i]; ++j) {
      cin >> x;
      --x;
      g[i].push_back(x);
      p[x] = i;
    }
  }

  dfsfile(0);
  dfsin(0);
  dfsans(0);

  cout << ans << '\n';

  return 0;
}
