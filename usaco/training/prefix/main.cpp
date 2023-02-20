/*
ID: saiansh1
LANG: C++
TASK: prefix
*/

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

    int size() {
      return p_hash.size() - 1;
    }
};
vector<ll> HashedString::pow = {1};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("prefix.in", "r", stdin);
  freopen("prefix.out", "w", stdout);

  // We can use string hashing and DP to run in O(|S| * |P|)
  string nx;
  cin >> nx;
  vector<HashedString> prims;
  while (nx != ".") {
    prims.push_back(HashedString(nx));
    cin >> nx;
  }

  string s;
  while (getline(cin, nx)) {
    for (auto &ch: nx) {
      if (ch != ' ') s += ch;
    }
  }
  HashedString h(s);

  vector<bool> dp(s.size()+1);
  dp[0] = 1;
  int mx{0};
  for (int i{0}; i < (int)s.size(); ++i) {
    if (dp[i]) {
      mx = i;
      for (auto &prim: prims) {
        if (prim.size() + i - 1 < (int)s.size() && h.getHash(i, i + prim.size() - 1) == prim.getHash(0, prim.size() - 1)) {
          dp[prim.size() + i] = 1;
        }
      }
    }
  }
  if (dp[s.size()]) mx = (int)s.size();

  cout << mx << '\n';

  return 0;
}
