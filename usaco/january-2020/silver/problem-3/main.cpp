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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  DSU dsu;
  dsu.init(n);

  vector<int> p(n);
  for (int i{0}; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }

  vector<pair<int,pair<int,int>>> edges(m);
  for (int i{0}; i < m; ++i) {
    cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    --edges[i].second.first; --edges[i].second.second;
  }

  sort(edges.begin(), edges.end());

  int pos{edges.size()-1};
  for (int i{0}; i < n; ++i) {
    while (pos && !dsu.sameSet(i, p[i])) {
      dsu.unite(edges[pos].second.first, edges[pos].second.second);
      --pos;
    }
  }
  ++pos;

  cout << (pos == edges.size() ? -1 : edges[pos].first) << '\n';

  return 0;
}
