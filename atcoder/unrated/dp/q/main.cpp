#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
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

  vector<ll> h(n), a(n);
  vector<ll> decompress;
  for (int i{0}; i < n; ++i) {
    cin >> h[i];
    decompress.push_back(h[i]);
  }
  sort(decompress.begin(), decompress.end());
  decompress.erase(unique(decompress.begin(), decompress.end()), decompress.end());
  unordered_map<int,int> compress;
  for (int i{0}; i < (int)decompress.size(); ++i) {
    compress[decompress[i]] = i;
  }
  for (int i{0}; i < n; ++i) cin >> a[i];

  Tree dp(decompress.size()+2);
  for (int i{0}; i < n; ++i) {
    dp.update(compress[h[i]], dp.query(0, compress[h[i]]+1) + a[i]);
  }

  cout << dp.query(0, decompress.size()) << "\n";

  return 0;
}
