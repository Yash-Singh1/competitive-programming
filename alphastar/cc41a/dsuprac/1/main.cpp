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

  int n, q;
  cin >> n >> q;

  vector<pair<int,pii>> e(n-1);
  for (int i{0}; i < n-1; ++i) {
    cin >> e[i].second.first >> e[i].second.second >> e[i].first;
    --e[i].second.first; --e[i].second.second;
  }

  sort(e.begin(), e.end(), greater<pair<int,pii>>());

  vector<pair<pii,int>> qs(q);
  vector<int> ans(q);
  for (int i{0}; i < q; ++i) {
    cin >> qs[i].first.first >> qs[i].first.second;
    --qs[i].first.second;
    qs[i].second = i;
  }
  sort(qs.begin(), qs.end(), greater<pair<pii,int>>());

  DSU dsu;
  dsu.init(n);

  int ep{0};
  for (int i{0}; i < q; ++i) {
    while (ep < n-1 && e[ep].first >= qs[i].first.first) {
      dsu.unite(e[ep].second.first, e[ep].second.second);
      ++ep;
    }
    ans[qs[i].second] = dsu.size(qs[i].first.second);
  }

  for (auto &anse: ans) {
    cout << anse-1 << '\n';
  }

  return 0;
}
