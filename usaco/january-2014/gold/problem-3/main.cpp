#include <bits/stdc++.h>

using namespace std;

int t;

typedef pair<int,int> pii;
typedef long long ll;

// KACTL DSU Implementation

typedef vector<int> vi;

struct DSU {
	vi e, mw; int sets; void init(int N) { e = vi(N,-1); mw = vi(N,-1); sets = N; }
	int get(int x) {
    getmw(x);
    return e[x] < 0 ? x : e[x] = get(e[x]);
  }
  int getmw(int x) {
    if (mw[x] == -1) {
      return e[x] < 0 ? -1 : (mw[x] = getmw(e[x]));
    }
    return mw[x];
  }
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y, int w) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
    --sets;
		e[x] += e[y];
    if (mw[x] == -1 && size(x) >= t) mw[x] = w;
    if (t == 1) mw[x] = 0;
    if (size(y) < t && size(x) >= t) mw[y] = w;
    e[y] = x;
    return 1;
	}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("skilevel.in", "r", stdin);
  freopen("skilevel.out", "w", stdout);

  int n, m;
  cin >> n >> m >> t;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> grid[i][j];
    }
  }
  vector<pii> starts;
  int val;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> val;
      if (val) {
        starts.push_back({i, j});
      }
    }
  }

  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  // ~Binary search optimal D and run O(MN) check~
  // That'll be suboptimal, instead we can iterate over all 1e6 possible edge weights and add them one by one
  DSU dsu;
  dsu.init(m*n);
  vector<pair<int,pii>> edges;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      for (int k{0}; k < 4; ++k) {
        if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= m) continue;
        edges.push_back({abs(grid[i][j] - grid[i + dx[k]][j + dy[k]]), {(i*m)+j, ((i+dx[k])*m)+j+dy[k]}});
      }
    }
  }

  sort(edges.begin(), edges.end());

  for (auto &e: edges) {
    dsu.unite(e.second.first, e.second.second, e.first);
  }

  ll ans{0};
  for (auto &st: starts) {
    dsu.get(st.first*m+st.second);
    ans += dsu.getmw(st.first*m+st.second);
  }

  cout << ans << "\n";

  return 0;
}
