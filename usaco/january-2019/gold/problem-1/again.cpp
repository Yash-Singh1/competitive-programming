#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

ll binpow(ll a, ll b, ll m) {
  if (b == 0) {
    return 1;
  } else if (a == 0) {
    return 0;
  }
  ll curp{a};
  ll pow{0};
  ll ans{1};
  while (b) {
    if (b & (1<<pow)) {
      b &= b - 1;
      ans *= curp;
      ans %= m;
    }
    ++pow;
    curp *= curp;
    curp %= m;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("poetry.in", "r", stdin);
  freopen("poetry.out", "w", stdout);

  int n, m, k;
	cin >> n >> m >> k;

	map<char, int> f;

	vector<pair<int,int>> words(n); // {length, class}
	for (int i{0}; i < n; ++i) {
		cin >> words[i].first >> words[i].second;
	}

	char x;
	for (int i{0}; i < m; ++i) {
		cin >> x;
		++f[x];
	}

	// Precompute factorials
	vector<ll> fact(n*k+1);
	fact[0] = 1;
	for (int i{1}; i <= n*k; ++i) {
		fact[i] = fact[i -1] * i;
		fact[i] %= MOD;
	}

	vector<int> dpf(n+1);
	vector<int> dp(k+1);
	dp[0] = 1;

	for (int j{0}; j < k; ++j) {
		if (!dp[j]) continue;

		for (int i{0}; i < n; ++i) {
			if (j + words[i].first > k) continue;
			else if (j + words[i].first == k) {
				dpf[words[i].second] += dp[j];
				dpf[words[i].second] %= MOD;
			} else {
				dp[j + words[i].first] += dp[j];
				dp[j + words[i].first] %= MOD;
			}
		}
	}

	ll ans{1};
	for (auto &letter: f) {
		ll loc{0};
		for (int i{0}; i <= n; ++i) {
			if (!dpf[i]) continue;
			loc += binpow(dpf[i], (ll)letter.second, MOD);
			loc %= MOD;
		}
		ans *= loc;
		ans %= MOD;
	}

	cout << ans << '\n';

  return 0;
}
