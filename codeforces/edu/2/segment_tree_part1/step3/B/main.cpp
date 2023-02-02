#include <bits/stdc++.h>

using namespace std;

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; } // (any associative fn)
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

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  Tree st(n+3);
  vector<int> vis(n);
  for (int i{1}; i <= n; ++i) {
    st.update(i, 1);
    vis[i-1]=1;
  }

  vector<int> anse(n);
  for (int i{n-1}; i >= 0; --i) {
    int l{1}, r{n}, ans{-1};
    while (l <= r) {
      int m{(l+r)/2}, tot{st.query(m, n+2)-1};
      // if (m == 3 && i == 1) {
      //   cout << m << " " << tot << " " << a[i] << "\n";
      // }
      if (tot < a[i]) {
        r = m - 1;
      } else {
        // if (i == 1) cout << tot << " " << l << " " << r << " " << m << "B\n";
        // if (i == 1) {
        //   for (auto &visited: vis) {
        //     cout << visited << " ";
        //   }
        //   cout << "\n";
        // }
        l = m + 1;
        if (st.query(m, m + 1) != 0) ans = m;
      }
    }
    st.update(ans, 0);
    if (ans > -1)vis[ans - 1] = 0;
    anse[i] = ans;
  }

  for (auto &ansp: anse) cout << ansp << " ";
  cout << "\n";

  return 0;
}
