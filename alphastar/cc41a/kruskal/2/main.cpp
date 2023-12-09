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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<pair<int,pii>> edge(m);
  for (int i{0}; i < m; ++i) {
    cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
    --edge[i].second.first; --edge[i].second.second;
  }

  sort(edge.begin(), edge.end());

  DSU dsu;
  dsu.init(n);

  int mn{0};
  for (auto &e: edge) {
    if (dsu.unite(e.second.first, e.second.second)) {
      mn += e.first;
    }
  }

  cout << mn << '\n';

  return 0;
}
