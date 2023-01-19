#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

  int n, m;
  cin >> n >> m;

  vector<pair<int,pair<int,int>>> adj(m);
  for (int i{0}; i < m; ++i) {
    cin >> adj[i].second.first >> adj[i].second.second >> adj[i].first;
    --adj[i].second.first; --adj[i].second.second;
  }

  sort(adj.begin(), adj.end());

  DSU dsu;
  dsu.init(n);
  ll sm{0};
  for (int i{0}; i < m && dsu.sets > 1; ++i) {
    if (dsu.unite(adj[i].second.first, adj[i].second.second)) {
      sm += adj[i].first;
    }
  }
  
  if (dsu.sets > 1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  cout << sm << "\n";

  return 0;
}
