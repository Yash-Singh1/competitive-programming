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

  // 4N locations
  // since we are merging cyclic components, there are no compromises

  int n;
  cin >> n;

  vector<pii> c(n);
  DSU dsu;
  dsu.init(n*4);
  vector<int> seen(n*2, -1);
  int x;
  for (int i{0}; i < n; ++i) {
    cin >> c[i].first;
    c[i].second = i;
    for (int j{0}; j < 4; ++j) {
      cin >> x;
      --x;
      if (seen[x] >= 0) {
        dsu.unite(i*4+j, seen[x]);
      } else {
        seen[x] = i*4+j;
      }
    }
    dsu.unite(i*4,i*4+1);
    dsu.unite(i*4+2,i*4+3);
  }

  sort(c.begin(), c.end());
  int ans{0};
  for (int i{0}; i < n; ++i) {
    if (dsu.unite(c[i].second*4+1,c[i].second*4+3)) {
      ans += c[i].first;
    }
  }

  cout << ans << '\n';

  return 0;
}
