#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

// KACTL DSU Implementation

typedef vector<ll> vi;

struct DSU {
	vi e; ll sets; void init(ll N) { e = vi(N,-1); sets = N; }
	ll get(ll x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(ll a, ll b) { return get(a) == get(b); }
	ll size(ll x) { return -e[get(x)]; }
	bool unite(ll x, ll y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
    --sets;
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("fencedin.in", "r", stdin);
  freopen("fencedin.out", "w", stdout);

  ll a, b, n, m;
  cin >> a >> b >> n >> m;

  vector<ll> h(m), v(n);
  for (ll i{0}; i < n; ++i) {
    cin >> v[i];
  }
  for (ll i{0}; i < m; ++i) {
    cin >> h[i];
  }
  sort(v.begin(), v.end());
  sort(h.begin(), h.end());
  vector<pair<ll,pll>> adj(n * (m + 1) + m * (n + 1));
  ll cur{0};
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j < m; ++j) {
      adj[cur++] = {v[i] - (i == 0 ? 0 : v[i - 1]), {i + j * (n + 1), i + (j + 1) * (n + 1)}};
      adj[cur++] = {h[j] - (j == 0 ? 0 : h[j - 1]), {i + j * (n + 1), i + 1 + j * (n + 1)}};
    }
  }
  for (ll i{0}; i < n; ++i) {
    adj[cur++] = {b - h[m - 1], {m * (n + 1) + i, m * (n + 1) + i + 1}};
  }
  for (ll i{0}; i < m; ++i) {
    adj[cur++] = {a - v[n - 1], {i * (n + 1) + n, (i + 1) * (n + 1) + n}};
  }
  sort(adj.begin(), adj.end());

  // for (auto &edge: adj) {
  //   cout << edge.first << " " << edge.second.first << " " << edge.second.second << "\n";
  // }

  DSU dsu;
  dsu.init((n + 1) * (m + 1));
  ll ans{0};
  for (ll i{0}; i < adj.size() && dsu.sets > 1; ++i) {
    if (dsu.unite(adj[i].second.first, adj[i].second.second)) {
      ans += adj[i].first;
    }
  }

  cout << ans << "\n";

  return 0;
}
