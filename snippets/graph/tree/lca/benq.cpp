// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

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
	int N; V<vi> adj;
	vi depth, pos, par, rev; // rev is for compress
	V<pair<int,int>> tmp; RMQ<pair<int,int>> r;
	void init(int _N) { N = _N; adj.resize(N); 
		depth = pos = par = rev = vi(N); }
	void ae(int x, int y) { adj[x].push_back(y), adj[y].push_back(x); }
	void dfs(int x) {
		pos[x] = (int)tmp.size(); tmp.emplace_back(depth[x],x); 
		for (auto &y: adj[x]) if (y != par[x]) {
			depth[y] = depth[par[y]=x]+1, dfs(y);
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
	int n;
	cin >> n;

	LCA lca;
	lca.init(n);

	int x, y;
	for (int i{1}; i < n; ++i) {
		cin >> x >> y;
		lca.ae(--x, --y);
	}
	lca.gen();

	int q;
	cin >> q;
	while (q--) {
		cin >> x >> y;
		--x; --y;
		cout << lca.dist(x, y) << "\n";
	}

	return 0;
}
