#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
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

  vector<vector<int>> a(n, vector<int>(4));
  vector<int> pportal(2*n, -1);
  vector<pii> cost(n);
  vector<vector<int>> g(4*n);
  DSU dsu; dsu.init(4*n);
  for (int i{0}; i < n; ++i) {
    cin >> cost[i].first;
    cost[i].second = i;
    cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    for (int j{0}; j < 4; ++j) {
      --a[i][j];
      if (pportal[a[i][j]] == -1) {
        pportal[a[i][j]] = i*4+j;
      } else {
        dsu.unite(i*4+j, pportal[a[i][j]]);
        g[i*4+j].push_back(pportal[a[i][j]]);
        g[pportal[a[i][j]]].push_back(i*4+j);
      }
    }
    dsu.unite(i*4, i*4+1);
    dsu.unite(i*4+2, i*4+3);
  }

  sort(cost.begin(), cost.end());
  int cst{0};
  for (int i{0}; i < (int)cost.size() && dsu.sets > 1; ++i) {
    if (dsu.unite(cost[i].second*4, cost[i].second*4+3)) {
      cst += cost[i].first;
    }
  }

  cout << cst << "\n";

  return 0;
}
