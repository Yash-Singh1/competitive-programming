#include <bits/stdc++.h>

using namespace std;

struct Tree {
	typedef pair<int,int> T;
	static constexpr T unit = {INT_MAX, -1};
	T f(T a, T b) { if (a.first < b.first) return a; else return b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

vector<int> tour, first, depth;
vector<vector<int>> g;

void dfs(int u, int p) {
  first[u] = tour.size();
  tour.push_back(u);
  if (p > -1) depth[u] = depth[p] + 1;
  for (auto &v: g[u]) {
    if (v != p) {
      dfs(v, u);
      tour.push_back(u);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  tour.reserve(2*n);
  g.resize(n); first.resize(n); depth.resize(n);
  int x;
  for (int i{1}; i < n; ++i) {
    cin >> x;
    --x;
    g[x].push_back(i);
  }

  dfs(0, -1);

  Tree st(2*n+5);
  for (int i{0}; i < (int)tour.size(); ++i) {
    st.update(i+1, {depth[tour[i]], tour[i]+1});
  }

  int y;
  while (q--) {
    cin >> x >> y;
    --x; --y;
    cout << st.query(min(first[x], first[y]), max(first[x], first[y])).second << '\n';
  }

  return 0;
}
