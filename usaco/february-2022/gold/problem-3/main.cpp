#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pii> points(n);
  for (int i{0}; i < n; ++i) {
    cin >> points[i].first >> points[i].second;
  }

  sort(points.begin(), points.end());

  vector<pair<ll,pii>> edges;
  vector<int> mxy(11, -1);
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < 11; ++j) {
      if (mxy[j] != -1) {
        edges.push_back({(ll)pow(points[i].first - points[mxy[j]].first, 2) + (ll)pow(points[i].second - points[mxy[j]].second, 2), {mxy[j], i}});
      }
    }
    mxy[points[i].second] = i;
  }

  sort(edges.begin(), edges.end());
  DSU dsu;
  dsu.init(n);
  ll ans{0};
  for (auto &edge: edges) {
    if (dsu.unite(edge.second.first, edge.second.second)) {
      ans += edge.first;
    }
  }

  cout << ans << "\n";

  return 0;
}
