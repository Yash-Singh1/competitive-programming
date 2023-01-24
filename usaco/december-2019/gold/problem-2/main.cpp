#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

struct segtree {
  int size;
  vector<ll> tree;
  void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    tree.assign(2 * size, INT_MAX);
  }

  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m) {
      set(i, v, 2 * x + 1, lx, m);
    } else {
      set(i, v, 2 * x + 2, m, rx);
    }
    tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
  }

  void set(int i, int v) {
    set(i, v, 0, 0, size);
  }

  ll mn(int l, int r, int x, int lx, int rx) {
    if (lx >= r || l >= rx) return INT_MAX;
    if (lx >= l && rx <= r) {
      return tree[x];
    }
    int m = (lx + rx) / 2;
    return min(mn(l, r, 2 * x + 1, lx, m), mn(l, r, 2 * x + 2, m, rx));
  }

  ll mn(int l, int r) {
    return mn(l, r, 0, 0, size);
  }
};

unordered_map<int,stack<int>> ss;
vector<vector<pair<pii,int>>> queries;
vector<int> ans, type, depth;
vector<int> lca;
vector<vector<int>> g;
unordered_map<int,int> lcab;
segtree st;

void dfs(int u, int p) {
  ss[type[u]].push(u);
  for (auto &query: queries[u]) {
    if (ss.find(query.first.second) != ss.end() && ss[query.first.second].size() && st.mn(min(lcab[u], lcab[query.first.first]), max(lcab[u], lcab[query.first.first]) + 1) <= depth[ss[query.first.second].top()]) {
      // cout << query.second << " " << st.mn(min(lcab[u], lcab[query.first.first]), max(lcab[u], lcab[query.first.first]) + 1) << " " << depth[ss[query.first.second].top()] << "\n";
      ans[query.second] = 1;
    }
  }
  for (auto &v: g[u]) {
    if (v != p) dfs(v, u);
  }
  ss[type[u]].pop();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("milkvisits.in", "r", stdin);
  freopen("milkvisits.out", "w", stdout);

  // We can run a DFS search from farm 1
  // We can also maintain an array of stacks for each type
  // For each of the queries on each of the nodes, if the closest for the expected type is under the LCA, we answer true
  // Otherwise, we leave it alone
  // We have to check queries on both sides

  int n, m;
  cin >> n >> m;

  type.resize(n);
  for (int i{0}; i < n; ++i) cin >> type[i];

  g.resize(n);
  int x, y;
  for (int i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  int z;
  depth.resize(n);
  queries.resize(n);
  depth[0] = 0;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    queries[x].push_back({{y, z}, i});
    queries[y].push_back({{x, z}, i});
  }

  stack<pii> s;
  s.push({0, -1});
  while (s.size()) {
    int u = s.top().first;
    int p = s.top().second;
    s.pop();
    if (p >= 0) {
      depth[u] = depth[p] + 1;
      lcab[p] = lca.size();
      lca.push_back(p);
    }
    if (g[u].size() == 1) {
      lcab[u] = lca.size();
      lca.push_back(u);
    }
    for (auto &v: g[u]) {
      if (v != p) {
        s.push({v, u});
      }
    }
  }

  ans.resize(m);
  st.init(lca.size());

  for (int i{0}; i < (int)lca.size(); ++i) {
    st.set(i, depth[lca[i]]);
  }

  dfs(0, -1);

  for (auto &ansp: ans) cout << ansp;
  cout << "\n";

  return 0;
}
