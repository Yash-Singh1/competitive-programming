// Required simplification of Contribution Technique Formula from one of Errichto's videos

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
	cin >> t;

	vector<ll> p2(100001);
	p2[0] = 1;
	for (ll i{1}; i <= 100000; ++i) {
		p2[i] = p2[i-1] * 2;
		p2[i] %= MOD;
	}

	ll n;
	while (t--) {
		cin >> n;
		ll ans{0};
		for (ll i{2}; i <= n; ++i) {
			ans += (p2[i] * (p2[n-i+1]-1) % MOD) * (p2[n] - p2[n-i+1]) % MOD;
			ans %= MOD;
		}
		cout << ans << '\n';
	}

  return 0;
}
