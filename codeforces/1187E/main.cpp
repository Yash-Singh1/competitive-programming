#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll>> g;
vector<ll> dp1, dp2;
vector<ll> prec1, prec2;
vector<ll> ad, sz;

void dfs1(ll u, ll p) {
  sz[u] = 1;
  for (auto &v: g[u]) {
    if (v == p) continue;
    dfs1(v, u);
    sz[u] += sz[v];
    dp1[u] += dp1[v];
  }
  dp1[u] += sz[u];
}

void dfsmd(ll u, ll p) {
  if (p != -1) {
    prec1[u] = prec1[p] + sz[p] - sz[u];
    prec2[u] = prec2[p] + prec1[u] + sz[p] - sz[u];
  }
  for (auto &v: g[u]) {
    if (v == p) continue;
    dfsmd(v, u);
  }
}

void dfs2(ll u, ll p) {
  dp2[u] = (g[u].size() == 1 ? prec2[u]+1 : 0);
  ad[u] = 1;
  ll tot{0};
  for (auto &v: g[u]) {
    if (v == p) continue;
    tot += dp1[v];
  }
  for (auto &v: g[u]) {
    if (v == p) continue;
    dfs2(v, u);
    if ((dp2[v] + tot - dp1[v]) > dp2[u]
      // ||  (((sz[u] - sz[v]) * (ad[v] + 1) + dp2[v] + tot - dp1[v]) == dp2[u] && ad[v] + 1 > ad[u])
    ) {
      dp2[u] = (dp2[v] + tot - dp1[v]);
      ad[u] = ad[v] + 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  g.resize(n); dp1.resize(n); dp2.resize(n); sz.resize(n); ad.resize(n);
  prec1.resize(n); prec2.resize(n);

  ll x, y;
  for (ll i{1}; i < n; ++i) {
    cin >> x >> y; --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs1(0, -1);
  dfsmd(0, -1);
  dfs2(0, -1);

  ll ans{0};
  for (ll i{0}; i < n; ++i) {
    ans = max(ans, max(dp1[i], dp2[i]));
  }

  cout << ans << '\n';

  return 0;
}
