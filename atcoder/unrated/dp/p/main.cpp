#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mulmod(ll a, ll b, ll m) {
  a %= m;
  b %= m;
  return (ll)(((__int128)a * (__int128)b) % m);
}

const ll MOD = (ll)1e9+7;
vector<vector<int>> g;
vector<ll> white, black;

void dfs(int u, int p) {
  for (auto &v: g[u]) {
    if (v != p) {
      dfs(v, u);
      black[u] = mulmod(black[u], white[v], MOD);
      white[u] = mulmod(white[u], white[v] + black[v], MOD);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  g.resize(n);
  white.assign(n, 1LL);
  black.assign(n, 1LL);

  int x, y;
  for (int i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(0, -1);
  cout << (white[0] + black[0]) % MOD << "\n";

  return 0;
}
