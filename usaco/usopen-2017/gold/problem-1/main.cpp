#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll M = 1e9+7;
const ll B = 27;
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

  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  string x(m, 'a');
  vector<HashedString> spotty, plain;
  for (int i{0}; i < n; ++i) {
    cin >> x;
    spotty.push_back(HashedString(x));
  }
  for (int i{0}; i < n; ++i) {
    cin >> x;
    plain.push_back(HashedString(x));
  }

  int l{1}, r{m}, ans{-1};
  while (l <= r) {
    int md{(l+r)/2};
    bool win{0};
    for (int i{0}; i < m - md + 1; ++i) {
      unordered_set<ll> vals;
      for (int j{0}; j < n; ++j) {
        vals.insert(spotty[j].getHash(i, i + md - 1));
      }
      bool success{1};
      for (int j{0}; j < n; ++j) {
        if (vals.find(plain[j].getHash(i, i + md - 1)) != vals.end()) {
          success = 0;
          break;
        }
      }
      if (success) {
        win = 1;
        break;
      }
    }
    if (win) {
      ans = md;
      r = md - 1;
    } else {
      l = md + 1;
    }
  }

  cout << ans << '\n';

  return 0;
}
