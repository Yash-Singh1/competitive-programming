#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) (S & -S)

vector<int> p;
vector<vector<int>> st, jump;

// KACTL DSU Implementation

typedef vector<int> vi;

struct DSU {
  vi e; int sets; void init(int N) { e = vi(N,-1); sets = N; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
  bool sameSet(int a, int b) { return get(a) == get(b); }
  int size(int x) { return -e[get(x)]; }
  bool unite(int x, int y, int i) { // union by size
    x = get(x), y = get(y); if (x == y) return 0;
    if (e[x] > e[y]) swap(x,y);
    --sets;
    p[y] = x;
    // st[0][y] = i;
    // jump[0][y] = x;
    e[x] += e[y]; e[y] = x; return 1;
  }
};


#define tcT template<class T

tcT> using V = vector<T>; 
typedef V<int> vi;

tcT> struct RMQ { // floor(log_2(x))
  int level(int x) { return 31-__builtin_clz(x); }
  V<T> v; V<vi> jmp;
  int cmb(int a, int b) {
    return v[a]==v[b]?min(a,b):(v[a]<v[b]?a:b); }
  void init(const V<T>& _v) {
    v = _v; jmp = {vi((int)v.size())};
    iota(jmp[0].begin(), jmp[0].end(),0);
    for (int j = 1; 1<<j <= (int)v.size(); ++j) {
      jmp.push_back(vi((int)v.size()-(1<<j)+1));
      for (int i{0}; i < (int)jmp[j].size(); ++i) jmp[j][i] = cmb(jmp[j-1][i],
        jmp[j-1][i+(1<<(j-1))]);
    }
  }
  int index(int l, int r) {
    assert(l <= r); int d = level(r-l+1);
    return cmb(jmp[d][l],jmp[d][r-(1<<d)+1]); }
  T query(int l, int r) { return v[index(l,r)]; }
};

struct LCA {
  int N; V<V<pair<int,int>>> adj;
  vi depth, pos, par, rev; // rev is for compress
  V<pair<int,int>> tmp; RMQ<pair<int,int>> r;
  void init(int _N) { N = _N; adj.resize(N); 
    depth = pos = par = rev = vi(N); }
  void ae(int x, int y, int i) { adj[x].push_back({y, i}), adj[y].push_back({x, i}); }
  void dfs(int x) {
    pos[x] = (int)tmp.size(); tmp.emplace_back(depth[x],x); 
    for (auto &y: adj[x]) if (y.first != par[x]) {
      depth[y.first] = depth[par[y.first]=x]+1, dfs(y.first);
			st[0][y.first] = y.second;
      tmp.emplace_back(depth[x],x); }
  }
  void gen(int R = 0) { par[R] = R; dfs(R); r.init(tmp); }
  int lca(int u, int v){
    u = pos[u], v = pos[v]; if (u > v) swap(u,v);
    return r.query(u,v).second; }
  int dist(int u, int v) {
    return depth[u]+depth[v]-2*depth[lca(u,v)]; }
  V<pair<int,int>> compress(vi S) {
    auto cmp = [&](int a, int b) { return pos[a] < pos[b]; };
    sort(S.begin(), S.end(),cmp); for (int i{(int)S.size()-1}; i >= 0; --i) S.push_back(lca(S[i],S[i+1]));
    sort(S.begin(), S.end(),cmp); S.erase(unique(S.begin(), S.end()),S.end());
    V<pair<int,int>> ret{{0,S[0]}}; for (int i{0}; i < (int)S.size(); ++i) rev[S[i]] = i;
    for (int i{1}; i < (int)S.size(); ++i) ret.emplace_back(rev[lca(S[i-1],S[i])],S[i]);
    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("in.txt", "r", stdin);

  int n, m, q;
  cin >> n >> m >> q;

  // TODO: move st and jumping logic into the lca instead of dsu
  p.resize(n);
  st.assign(20, vector<int>(n, -1));
  jump.assign(20, vector<int>(n, -1));
  DSU dsu;
  dsu.init(n);
  LCA lca;
  lca.init(n);

  int x, y;
  for (int i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    if (!dsu.sameSet(x, y)) {
      dsu.unite(x, y, i);
      lca.ae(x, y, i);
    }
  }

  set<int> s;
  for (int i{0}; i < n; ++i) {
    if (s.find(dsu.get(i)) == s.end()) {
      s.insert(dsu.get(i));
      lca.par[dsu.get(i)] = dsu.get(i);
      lca.dfs(dsu.get(i));
    }
  }

  lca.r.init(lca.tmp);

	for (int i{0}; i < n; ++i) {
		jump[0][i] = lca.par[i];
	}

  for (int i{0}; i < 19; ++i) {
    for (int j{0}; j < n; ++j) {
      if (jump[i][j] != -1) {
        jump[i+1][j] = jump[i][jump[i][j]];
      }
    }
  }

  for (int i{0}; i < 19; ++i) {
    for (int j{0}; j < n; ++j) {
      if (st[i][j] != -1 && jump[i][j] != -1) {
        st[i+1][j] = max(st[i][j], st[i][jump[i][j]]);
      }
    }
  }

  while (q--) {
    cin >> x >> y;
    --x; --y;
    if (dsu.sameSet(x, y)) {
      int ll{lca.lca(x,y)};
      int jmp{lca.depth[x]-lca.depth[ll]};
      int cur{x};
      int ans{-1};
      while (jmp) {
        ans = max(ans, st[__builtin_ctz(jmp)][cur]);
        cur = jump[__builtin_ctz(jmp)][cur];
        jmp -= LSOne(jmp);
      }
      jmp = lca.depth[y]-lca.depth[ll];
      cur = y;
      while (jmp) {
        ans = max(ans, st[__builtin_ctz(jmp)][cur]);
        cur = jump[__builtin_ctz(jmp)][cur];
        jmp -= LSOne(jmp);
      }
      cout << ans+1 << '\n';
    } else {
      cout << -1 << '\n'; 
    }
  }

  return 0;
}
