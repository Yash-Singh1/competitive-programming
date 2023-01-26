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

  HashedString hs(s);

  ll n{(ll)s.size()};
  for (ll i{1}; i <= n; ++i) {
    ll orig{hs.getHash(0, i - 1)};
    bool right{1};
    for (ll j{i}; j < n; j += i) {
      if (j + i - 1 >= n) {
        if (hs.getHash(j, n - 1) != hs.getHash(0, (n - 1 - j))) {
          right = 0;
          break;
        }
      } else if (hs.getHash(j, j + i - 1) != orig) {
        right = 0;
        break;
      }
    }
    if (right) {
      cout << i << " ";
    }
  }

  cout << "\n";

  return 0;
}
