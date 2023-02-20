#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> dp1, dp2;
ll MOD;
vector<vector<ll>> g;
vector<vector<ll>> suff;

void dfs1(ll u, ll p) {
  dp1[u] = 1;
  ll i{0}, found{-1};
  for (auto &v: g[u]) {
    if (v == p) {
      found = i;
      continue;
    }
    dfs1(v, u);
    dp1[u] *= dp1[v];
    dp1[u] %= MOD;
    ++i;
  }
  if (found != -1) g[u].erase(g[u].begin() + found);
  ++dp1[u];
  dp1[u] %= MOD;
  // We must setup some form of suffix multiplication for the calculation of dfs2
  if (g[u].size()) suff[u].push_back(dp1[g[u][g[u].size() - 1]]);
  for (ll i{(ll)g[u].size() - 2}; i >= 0; --i) {
    suff[u].push_back((dp1[g[u][i]] * suff[u].back()) % MOD);
  }
  reverse(suff[u].begin(), suff[u].end());
}

void dfs2(ll u, ll p) {
  ll pre{1};
  for (ll i{0}; i < (ll)g[u].size(); ++i) {
    dp2[g[u][i]] = (((pre * ((i == (ll)g[u].size()-1) ? 1 : suff[u][i+1]) % MOD) * dp2[u]) % MOD + 1) % MOD;
    pre *= dp1[g[u][i]];
    pre %= MOD;
    dfs2(g[u][i], u);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n >> MOD;

  dp1.resize(n); dp2.resize(n); g.resize(n); suff.resize(n);

  // For each vertice, the answer is all the children's values multiplied by each other + 1
  // The root's answer is all children's values multiplied multiplied by the parent's answer
  // The initial value for any leaf node is 2
  // To calculate parent's value, we do our current parent's parent value times all children value's excluding ourselves + 1
  // The initial for the parent values is 1

  ll x, y;
  for (ll i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs1(0, -1);
  dp2[0] = 1;
  dfs2(0, -1);

  for (ll i{0}; i < n; ++i) {
    ll ans{dp2[i]};
    for (auto &v: g[i]) {
      ans *= dp1[v];
      ans %= MOD;
    }
    cout << ans << "\n";
  }

  return 0;
}
