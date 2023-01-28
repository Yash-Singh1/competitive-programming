#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll,ll> pii;

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

  ll t;
  cin >> t;

  ll n, m, k;
  while (t--) {
    cin >> n >> m >> k;
    list<pair<ll,pii>> edges;
    auto mn = edges.end();
    pair<ll,pii> newe;
    for (ll i{0}; i < m; ++i) {
      cin >> newe.second.first >> newe.second.second >> newe.first;
      --newe.second.first; --newe.second.second;
      edges.push_back(newe);
      if (mn == edges.end() || abs(k - newe.first) < abs(k - mn->first)) {
        mn = prev(edges.end());
      }
    }
    edges.sort();
    DSU dsu;
    dsu.init(n);
    ll mx{0}, ans{0};
    for (auto i = edges.begin(); i != edges.end() && dsu.sets > 1; i = next(i)) {
      if (dsu.unite((*i).second.first, (*i).second.second)) {
        mx = max((*i).first, mx);
        if ((*i).first > k) {
          ans += (*i).first - k;
        }
      }
    }
    if (!ans) {
      ans += k - mx;
      ll ans2{0};
      pair<ll,pii> mnv = *mn;
      edges.erase(mn);
      edges.push_front(mnv);
      dsu.init(n);
      mx = 0;
      for (auto i = edges.begin(); i != edges.end() && dsu.sets > 1; i = next(i)) {
        if (dsu.unite((*i).second.first, (*i).second.second)) {
          mx = max((*i).first, mx);
          if ((*i).first > k) {
            ans2 += (*i).first - k;
          }
        }
      }
      if (!ans2) {
        ans2 = k - mx;
      }
      ans = min(ans2, ans);
    }
    cout << ans << "\n";
  }

  return 0;
}
