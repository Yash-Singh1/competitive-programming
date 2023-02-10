#include <bits/stdc++.h>

using namespace std;

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
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

  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> a(2*n);
  for (int i{0}; i < 2*n; ++i) {
    cin >> a[i]; --a[i];
  }

  Tree st(2*n+5);
  vector<int> visited(n+1, -1);
  int ans{0};
  for (int i{0}; i < 2*n; ++i) {
    if (visited[a[i]] != -1) {
      ans += st.query(visited[a[i]]+1, i);
    }
    st.update(i, 1);
    st.update(visited[a[i]], -1);
    visited[a[i]] = i;
  }

  cout << ans/2 << "\n";

  return 0;
}
