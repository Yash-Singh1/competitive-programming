#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

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

int n;
vector<int> sz, cval;
vector<vector<int>> g;

int dfs(int u, int p) {
  int sm{0};
  cval.push_back(u);
  for (auto &v: g[u]) {
    if (v != p) {
      sm += dfs(v, u);
    }
  }
  ++sm;
  sz[u] = sm;
  return sm;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  FenwickTree ft(n);

  vector<int> color(n);
  map<int,queue<int>> cm;
  for (int i{0}; i < n; ++i) {
    cin >> color[i];
    // if (cm[color[i]].empty()) {
    //   ft.update(i+1, 1);
    //   // cout << 1;
    // }
    // // else cout << 0;
    // cm[color[i]].push(i);
  }
  // cout << "\n";

  int x, y;
  g.resize(n);
  for (int i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  sz.resize(n);
  dfs(0, -1);

  vector<int> temp(n);
  for (int i{0}; i < n; ++i) {
    if (cm[color[cval[i]]].empty()) {
      temp[cval[i]] = 1;
      ft.update(i + 1, 1);
    }
    cm[color[cval[i]]].push(i);
  }

  // for (int i{0}; i < n; ++i) cout << temp[i];
  // cout << "\n";

  // for (int i{0}; i < n; ++i) cout << sz[i] << " ";
  // cout << "\n";

  // for (int i{0}; i < n; ++i) cout << cval[i] << " ";
  // cout << "\n";

  vector<int> ans(n);
  for (int i{0}; i < n; ++i) {
    ans[cval[i]] = ft.rsq(i+1, i + sz[cval[i]]);
    ft.update(i+1, -1);
    cm[color[cval[i]]].pop();
    if (cm[color[cval[i]]].size()) {
      ft.update(cm[color[cval[i]]].front()+1, 1);
    }
  }

  for (auto &ansp: ans) cout << ansp << " ";
  cout << "\n";

  return 0;
}
