#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

vector<ll> val, sz, flat, dist;
vector<vector<ll>> g;
unordered_map<ll,ll> flatid;

#define LSOne(S) ((S) & -(S))

typedef vector<ll> vll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

class FenwickTree {
private:
  vll ft;
public:
  FenwickTree(ll m) { ft.assign(m+1, 0); }

  void build(const vll &f) {
    ll m = (ll)f.size()-1;
    ft.assign(m+1, 0);
    for (ll i = 1; i <= m; ++i) {
      ft[i] += f[i];
      if (i+LSOne(i) <= m)
        ft[i+LSOne(i)] += ft[i];
    }
  }

  FenwickTree(const vll &f) { build(f); }

  FenwickTree(ll m, const vi &s) {
    vll f(m+1, 0);
    for (ll i = 0; i < (ll)s.size(); ++i)
      ++f[s[i]];
    build(f);
  }

  FenwickTree(ll m, const vi &s, ll x, ll y) {
    vll f(m+1, 0);
    for (ll i = x; i <= y; ++i)
      ++f[s[i]];
    build(f);
  }

  ll rsq(ll j) {
    if (j < 0) return 0;
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  ll rsq(ll i, ll j) { return rsq(j) - rsq(i-1); }

  void update(ll i, ll v) {
    for (; i < (ll)ft.size(); i += LSOne(i))
      ft[i] += v;
  }

  ll select(ll k) {
    ll p = 1;
    while (p*2 < (ll)ft.size()) p *= 2;
    ll i = 0;
    while (p) {
      if (i+p < (ll) ft.size() && k > ft[i+p]) {
        k -= ft[i+p];
        i += p;
      }
      p /= 2;
    }
    return i+1;
  }
};

ll dfs(ll u, ll p) {
  if (p >= 0) dist[u] = val[u] + dist[p];
  ll sm{1};
  flatid[u] = flat.size();
  flat.push_back(u);
  for (auto &v: g[u]) {
    if (v != p) {
      sm += dfs(v, u);
    }
  }
  sz[u] = sm;
  return sm;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q;
  cin >> n >> q;

  val.resize(n);
  sz.resize(n);
  dist.resize(n);
  for (ll i{0}; i < n; ++i) cin >> val[i];

  g.resize(n);
  ll x, y;
  for (ll i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dist[0] = val[0];
  dfs(0, -1);

  vector<ll> p(n);
  p[0] = dist[flat[0]];
  for (ll i{1}; i < n; ++i) {
    p[i] = dist[flat[i]] - dist[flat[i - 1]];
  }

  FenwickTree ft(n+1);
  for (ll i{0}; i < n; ++i) {
    ft.update(i + 1, p[i]);
  }

  while (q--) {
    cin >> x >> y;
    --y;
    if (x == 1) {
      cin >> x;
      ll up{x - val[y]};
      ft.update(flatid[y]+1, up);
      ft.update(flatid[y]+sz[y]+1, -up);
      val[y] = x;
    } else {
      cout << ft.rsq(flatid[y] + 1) << "\n";
    }
  }

  return 0;
}
