#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
// KACTL DSU Implementation

typedef vector<int> vi;

struct DSU {
  vector<bool> wps;
	vi e; int sets; int wpoints; void init(int N) { e = vi(N,-1); sets = N; wps = vector<bool>(N,0); wpoints = 0; }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
  bool iswp(int x) { return wps[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
    if (iswp(x) && iswp(y)) --wpoints;
    if (iswp(x)) wps[y] = 1;
    if (iswp(y)) wps[x] = 1;
    --sets;
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  vector<pair<int,pii>> e;
  e.reserve(4*n*m-2*n-2*m);

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      if (i) {
        e.push_back({abs(grid[i-1][j] - grid[i][j]), {(i-1)*m+j, i*m+j}});
      }
      if (j) {
        e.push_back({abs(grid[i][j-1] - grid[i][j]), {i*m+(j-1), i*m+j}});
      }
      if (j<m-1) {
        e.push_back({abs(grid[i][j+1] - grid[i][j]), {i*m+(j+1), i*m+j}});
      }
      if (i<n-1) {
        e.push_back({abs(grid[i+1][j] - grid[i][j]), {(i+1)*m+j, i*m+j}});
      }
    }
  }

  sort(e.begin(), e.end());

  DSU dsu;
  dsu.init(n*m);
  int nx;
  for (int i{0}; i < n*m; ++i) {
    cin >> nx;
    if (nx) {
      ++dsu.wpoints;
      dsu.wps[i] = 1;
    }
  }

  int mn{0};
  for (auto &ee: e) {
    if (dsu.wpoints == 1) {
      break;
    } else {
      mn = ee.first;
      dsu.unite(ee.second.first, ee.second.second);
      // cout << mn << ' ' << dsu.wpoints << ' ' << ee.second.first << "," << ee.second.second << '\n';
    }
  }

  cout << mn << '\n';

  return 0;
}
