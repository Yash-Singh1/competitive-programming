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

int n, q;
vector<vector<int>> g(200000);
vector<int> val(200000);
vector<int> cval;
vector<int> id;
vector<int> sz(200000);
unordered_map<int,int> back;

int dfs(int u, int p) {
  back[u] = cval.size();
  cval.push_back(val[u]);
  id.push_back(u);
  int childs{0};
  for (auto &v: g[u]) {
    if (v != p) childs += dfs(v, u);
  }
  sz[u] = childs + 1;
  return childs + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;

  for (int i{0}; i < n; ++i) cin >> val[i];

  int x, y;
  for (int i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(0, -1);

  FenwickTree ft(n);
  for (int i{0}; i < n; ++i) {
    ft.update(i + 1, cval[i]);
  }

  int t, s;
  while (q--) {
    cin >> t >> s;
    --s;
    if (t == 1) {
      int x;
      cin >> x;
      ft.update(back[s] + 1, x - cval[back[s]]);
      cval[back[s]] = x;
    } else {
      cout << ft.rsq(back[s] + 1, back[s] + sz[s]) << "\n";
    }
  }

  return 0;
}
