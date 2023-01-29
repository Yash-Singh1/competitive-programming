#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  int n, m;
  while (t--) {
    cin >> n >> m;
    Tree st(n+1);
    vector<int> mn(n, n);
    int x, y;
    for (int i{0}; i < m; ++i) {
      cin >> x >> y;
      --x; --y;
      if (y < x) swap(x,y);
      mn[x] = min(mn[x], y);
    }
    for (int i{0}; i < n; ++i) {
      st.update(i, mn[i]);
    }
    ll ans{0};
    for (int i{0}; i < n; ++i) {
      ans += st.query(i, n) - i;
    }
    cout << ans << "\n";
  }

  return 0;
}
