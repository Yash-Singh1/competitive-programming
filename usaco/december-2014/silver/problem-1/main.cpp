#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("piggyback.in", "r", stdin);
  freopen("piggyback.out", "w", stdout);

  ll b, e, p, n, m;
  cin >> b >> e >> p >> n >> m;

  // Answer = min(1->N * B + 2->N * E, mineachk(1->k * B + 2->k * E + k->N * P))
  vector<ll> distb(n, LLONG_MAX), diste(n, LLONG_MAX);

  vector<vector<ll>> g(n);
  ll x, y;
  for (ll i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  queue<pii> q;
  q.push({0, 0});
  distb[0] = 0;
  while (q.size()) {
    ll d = q.front().first;
    ll u = q.front().second;
    q.pop();
    if (d != distb[u]) continue;
    for (auto &v: g[u]) {
      if (d + 1 < distb[v]) {
        distb[v] = d+1;
        q.push({d+1, v});
      }
    }
  }

  q.push({0, 1});
  diste[1] = 0;
  while (q.size()) {
    ll d = q.front().first;
    ll u = q.front().second;
    q.pop();
    if (d != diste[u]) continue;
    for (auto &v: g[u]) {
      if (d + 1 < diste[v]) {
        diste[v] = d+1;
        q.push({d+1, v});
      }
    }
  }

  vector<ll> distp(n, LLONG_MAX);

  q.push({0, n-1});
  distp[n-1] = 0;
  while (q.size()) {
    ll d = q.front().first;
    ll u = q.front().second;
    q.pop();
    if (d != distp[u]) continue;
    for (auto &v: g[u]) {
      if (d + 1 < distp[v]) {
        distp[v] = d+1;
        q.push({d+1, v});
      }
    }
  }

  ll ans{LLONG_MAX};
  for (ll i{0}; i < n; ++i) {
    ans = min(ans, distb[i] * b + diste[i] * e + distp[i] * p);
  }

  cout << ans << '\n';

  return 0;
}
