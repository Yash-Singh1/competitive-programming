#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pii;

class FenwickTree {
private:
  vll ft;
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }

  void build(const vll &f) {
    int m = (int)f.size()-1;
    ft.assign(m+1, 0);
    for (int i = 1; i <= m; ++i) {
      ft[i] += f[i];
      if (i+LSOne(i) <= m)
        ft[i+LSOne(i)] += ft[i];
    }
  }

  FenwickTree(const vll &f) { build(f); }

  FenwickTree(int m, const vi &s) {
    vll f(m+1, 0);
    for (int i = 0; i < (int)s.size(); ++i)
      ++f[s[i]];
    build(f);
  }

  FenwickTree(int m, const vi &s, int x, int y) {
    vll f(m+1, 0);
    for (int i = x; i <= y; ++i)
      ++f[s[i]];
    build(f);
  }

  ll rsq(int j) {
    if (j < 0) return 0;
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); }

  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }

  int select(ll k) {
    int p = 1;
    while (p*2 < (int)ft.size()) p *= 2;
    int i = 0;
    while (p) {
      if (i+p < (int) ft.size() && k > ft[i+p]) {
        k -= ft[i+p];
        i += p;
      }
      p /= 2;
    }
    return i+1;
  }
};

vector<int> tour, tstart;
vector<int> sz;
vector<vector<int>> g;

void dfs(int u) {
  sz[u] = 1;
  tstart[u] = tour.size();
  tour.push_back(u);
  for (auto &v: g[u]) {
    dfs(v);
    sz[u] += sz[v];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("promote.in", "r", stdin);
  freopen("promote.out", "w", stdout);

  int n;
	cin >> n;

	vector<pii> val(n);
	for (int i{0}; i < n; ++i) {
		cin >> val[i].first;
    val[i].second = i;
	}
  sort(val.begin(), val.end(), greater<pii>());

	int x;
  g.resize(n);
	for (int i{1}; i < n; ++i) {
		cin >> x;
		--x;
		g[x].push_back(i);
	}

	sz.resize(n); tstart.resize(n);
	dfs(0);

  FenwickTree ft(n+2);
  vector<int> ans(n);
  for (int i{0}; i < n; ++i) {
    ans[val[i].second] = ft.rsq(tstart[val[i].second]+1, tstart[val[i].second] + sz[val[i].second]);
    ft.update(tstart[val[i].second]+1, 1);
  }

  for (int i{0}; i < n; ++i) {
    cout << ans[i] << "\n";
  }

  return 0;
}
