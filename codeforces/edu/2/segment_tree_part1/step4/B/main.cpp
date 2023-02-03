#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD;

struct Matrix {
  ll a, b, c, d;
  Matrix operator*(const Matrix& bm) const {
    return Matrix{((a * bm.a)%MOD + (b * bm.c)%MOD)%MOD, ((a * bm.b)%MOD + (b * bm.d)%MOD)%MOD, ((c * bm.a)%MOD + (d * bm.c)%MOD)%MOD, ((c * bm.b)%MOD + (d * bm.d)%MOD)%MOD};
  }
};

struct Tree {
	typedef Matrix T;
	static constexpr T unit = Matrix{1,0,0,1};
	T f(T a, T b) { return a*b; } // (any associative fn)
	vector<T> s; ll n;
	Tree(ll n2 = 0, T def = unit) : s(2*n2, def), n(n2) {}
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

  cin >> MOD;
  int n, m;
  cin >> n >> m;

  Tree st(n+2);
  Matrix x;
  for (int i{0}; i < n; ++i) {
    cin >> x.a >> x.b >> x.c >> x.d;
    st.update(i, x);
  }

  int l, r;
  while (m--) {
    cin >> l >> r;
    --l;
    Matrix ans = st.query(l, r);
    cout << ans.a << " " << ans.b << "\n" << ans.c << " " << ans.d << "\n" << "\n";
  }

  return 0;
}
