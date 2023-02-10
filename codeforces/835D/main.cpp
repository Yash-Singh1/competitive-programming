#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// String hashing template from USACO Guide
const ll M = LLONG_MAX-1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll B = uniform_int_distribution<ll>(27, 27)(rng);
class HashedString {
	private:
		static vector<ll> pow;
		vector<ll> p_hash;
	public:
		HashedString(const string& s) : p_hash(s.size() + 1) {
			while (pow.size() < s.size()) {
				pow.push_back((pow.back() * B) % M);
			}

			p_hash[0] = 0;
			for (int i = 0; i < (int)s.size(); i++) {
				p_hash[i + 1] = ((p_hash[i] * B) % M + (s[i] - 'a' + 1)) % M;
			}
		}

		ll getHash(int start, int end) {
			ll raw_val = (
				p_hash[end + 1] - (p_hash[start] * pow[end - start + 1])
			);
			return (raw_val % M + M) % M;
		}
};
vector<ll> HashedString::pow = {1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  HashedString h(s);
  reverse(s.begin(), s.end());
  HashedString r(s);
  int n{(int)s.size()};

  // If some string is a k-palindrome, and the consecutive string is equal, then the parent is a (k+1)-palindrome
  // All k-palindromes are also (k-1)-palindromes
  // That means we can use prefix sums and cap at k
  vector<vector<int>> k(n, vector<int>(n));
  for (int i{n - 1}; i >= 0; --i) {
    for (int j{i}; j < n; ++j) {
      if (h.getHash(i, j) == r.getHash(n - j - 1, n - i - 1)) {
        k[i][j] = max(k[i][j], 1);
        if ((j + 1 + (j - i)) < n) {
          if (h.getHash(i, j) == h.getHash(j + 1, j + 1 + (j - i))) {
            k[i][j + 1 + (j - i)] = max(k[i][j + 1 + (j - i)], k[i][j] + 1);
          }
          if ((j + 2 + (j - i)) < n) {
            if (h.getHash(i, j) == h.getHash(j + 2, j + 2 + (j - i))) {
              k[i][j + 2 + (j - i)] = max(k[i][j + 2 + (j - i)], k[i][j] + 1);
            }
          }
        }
      }
    }
  }

  vector<int> ans(n + 1);
  for (int i{0}; i < n; ++i) {
    for (int j{i}; j < n; ++j) {
      ++ans[0];
      --ans[k[i][j] + 1];
    }
  }

  for (int i{1}; i <= n; ++i) ans[i] = ans[i - 1] + ans[i];

  for (int i{1}; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}
