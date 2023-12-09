#include <bits/stdc++.h>

using namespace std;
// KACTL DSU Implementation

typedef vector<int> vi;

struct DSU {
	vi e; int sets; void init(int N) { e = vi(N,-1); sets = N; }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
    --sets;
		e[x] += e[y]; e[y] = x; return 1;
	}
};

typedef pair<int,int> pii;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<ll,ll>> p(n);
  for (int i{0}; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end());

  vector<pair<ll,pii>> e(n);
  e.reserve(10000000);
  vector<int> occ(11, -1);
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < 11; ++j) {
      if (occ[j] != -1) {
        e.push_back({(pow(p[i].second - j, 2) + pow(p[i].first - p[occ[j]].first, 2)), {i, occ[j]}});
      }
    }
    occ[p[i].second] = i;
  }

  sort(e.begin(), e.end());

  DSU dsu;
  dsu.init(n);

  ll ans{0};
  for (auto &edge: e) {
    if (dsu.unite(edge.second.first, edge.second.second)) {
      ans += edge.first;
    }
  }

  cout << ans << '\n';

  return 0;
}
