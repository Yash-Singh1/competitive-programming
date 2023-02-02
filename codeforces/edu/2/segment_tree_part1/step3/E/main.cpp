#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
	vector<T> s; ll n;
	Tree(ll n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(ll pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(ll b, ll e) { // query [b, e)
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

  ll n, m;
  cin >> n >> m;

  Tree st(n+2);
  vector<ll> val(n+1);
  ll t, x, y, v;
  while (m--) {
    cin >> t;
    if (t == 1) {
      cin >> x >> y >> v;
      val[x] += v;
      val[y] -= v;
      st.update(x, val[x]);
      st.update(y, val[y]);
    } else {
      cin >> x;
      cout << st.query(0, x+1) << "\n";
    }
  }

  return 0;
}
