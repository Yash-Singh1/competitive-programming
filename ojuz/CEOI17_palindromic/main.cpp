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

  // Slice bit by bit
  // Prefix and suffix maintained, once they match:
  // if they intersect then return so far + 1
  // otherwise slice prefix and suffix, add two to answer, and repeat

  int t;
  cin >> t;

  string s;
  while (t--) {
    cin >> s;
    int n{(int)s.size()};
    int curl{0}, curr{n - 1};
    int till{0}, tillr{n - 1};
    HashedString hs(s);
    int ans{0};
    while (true) {
      if (till >= tillr) {
        ++ans;
        break;
      }
      if (hs.getHash(curl, till) == hs.getHash(tillr, curr)) {
        curl = till + 1;
        curr = tillr - 1;
        ans += 2;
        if (curl == curr) ++ans;
        if (curl >= curr) break;
      }
      ++till;
      --tillr;
    }
    cout << ans << "\n";
  }

  return 0;
}
