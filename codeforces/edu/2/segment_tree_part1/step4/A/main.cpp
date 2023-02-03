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

  int n;
	cin >> n;

	vector<ll> a(n);
	for (int i{0}; i < n; ++i) cin >> a[i];

	Tree st(n);
	for (int i{0}; i < n; ++i) {
		if (i & 1) {
			st.update(i, -a[i]);
		} else st.update(i, a[i]);
	}

	int m;
	cin >> m;

	ll t, l, r;
	while (m--) {
		cin >> t >> l >> r;
		if (t == 0) {
			--l;
			if (l & 1) {
				st.update(l, -r);
			} else {
				st.update(l, r);
			}
		} else {
			--l;
			cout << st.query(l, r) * ((l & 1) ? -1 : 1) << "\n";
		}
	}

  return 0;
}
