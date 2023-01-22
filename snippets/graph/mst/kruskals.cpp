// KACTL DSU Implementation

typedef vector<int> vi;

struct DSU {
	vi e; int sets;
  void init(int N) { sets = N;
  e = vi(N,-1); }
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

vector<pair<int,pii>> adj;
// Read edge list...

sort(adj.begin(), adj.end());

DSU dsu;
int ans{0};
for (int i{0}; i < (int)adj.size() && dsu.sets > 1; ++i) {
  if (dsu.unite(adj.second.first, adj.second.second)) {
    ans += adj.first;
  }
}

return ans;
