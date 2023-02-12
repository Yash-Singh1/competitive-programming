#include <bits/stdc++.h>

using namespace std;

// KACTL DSU Implementation

typedef vector<int> vi;

struct DSU {
	vi e, enem; int sets; void init(int N) { e = vi(N,-1); enem = vi(N, -1); sets = N; }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) {
    if (a == -1 || b == -1) return 0;
    return get(a) == get(b);
  }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
    if (x == -1 || y == -1) return 0;
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
    --sets;
		e[x] += e[y]; e[y] = x;
    unite(enem[x], enem[y]);
    return 1;
	}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // First of all, we self-handle identity relationships, x ~ x or x * x
  // We maintain friends in a DSU
  // The enemies of a Disjoint Set can be represented as another Disjoint Set, because they are united

  int n;
  cin >> n;

  DSU dsu;
  dsu.init(n);

  int a, b, c;
  while (true) {
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) {
      break;
    }
    if (a == 1) {
      if ((dsu.enem[dsu.get(b)] != -1 && dsu.sameSet(dsu.enem[dsu.get(b)], c)) || (dsu.enem[dsu.get(c)] != -1 && dsu.sameSet(dsu.enem[dsu.get(c)], b))) {
        cout << "-1\n";
      } else {
        dsu.unite(b, c);
      }
    } else if (a == 2) {
      if (b == c || dsu.sameSet(b, c)) {
        cout << "-1\n";
      } else {
        if (dsu.enem[dsu.get(b)] == -1) {
          dsu.enem[dsu.get(b)] = dsu.get(c);
        } else {
          dsu.unite(dsu.enem[dsu.get(b)], c);
          dsu.enem[dsu.get(b)] = dsu.get(dsu.enem[dsu.get(b)]);
        }
        if (dsu.enem[dsu.get(c)] == -1) {
          dsu.enem[dsu.get(c)] = dsu.get(b);
        } else {
          dsu.unite(dsu.enem[dsu.get(c)], b);
          dsu.enem[dsu.get(c)] = dsu.get(dsu.enem[dsu.get(c)]);
        }
      }
    } else if (a == 3) {
      if (b == c || dsu.sameSet(b, c)) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    } else if (a == 4) {
      if (b != c && ((dsu.enem[dsu.get(b)] != -1 && dsu.sameSet(dsu.enem[dsu.get(b)], c)) || (dsu.enem[dsu.get(c)] != -1 && dsu.sameSet(dsu.enem[dsu.get(c)], b)))) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    }
  }

  return 0;
}
