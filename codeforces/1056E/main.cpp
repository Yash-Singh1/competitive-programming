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

  string zer, val;
	cin >> zer >> val;

	ll zers{0}, ones{0};
	for (auto &c: zer) {
		if (c == '0') ++zers;
		else ++ones;
	}
	HashedString hs(val);

	ll pos{0};
	ll n{(ll)val.size()};
	ll cz, j, k, co, ole;
	for (ll i{1}; i <= n; ++i) {
		if ((n-(i*zers)) > 0 && (n-(i*zers))%ones==0) {
			cz = -1; co = -1;
			ole = (n-(i*zers))/ones;
			if (!ole) goto end;
			j = 0;
			k = 0;
			for (; k < (ll)zer.size(); ++k) {
				if (zer[k] == '0') {
					if (cz != -1 && cz != hs.getHash(j, j + i - 1)) {
						goto end;
					}
					if (cz == -1) {
						cz = hs.getHash(j, j + i - 1);
					}
					j += i;
				} else {
					if (co != -1 && co != hs.getHash(j, j + ole - 1)) {
						goto end;
					}
					if (co == -1) {
						co = hs.getHash(j, j + ole - 1);
					}
					j += ole;
				}
			}
			if (cz == co) goto end;
			++pos;
		}
		end: continue;
	}

	cout << pos << "\n";

  return 0;
}
