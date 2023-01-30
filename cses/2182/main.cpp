#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

const ll MOD = (ll)1e9+7;

ll mulmod(ll a, ll b, ll m) {
  return (ll)(((__int128)a * (__int128)b) % m);
}

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
			ans = mulmod(ans, curp, m);
    }
    ++pow;
		curp = mulmod(curp, curp, m);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
	cin >> n;

	ll divisors{1}, sm{1}, prod{1};
	vector<pll> prim;
  vector<ll> pre(n), suf(n);

	int x, k;
	for (int i{0}; i < n; ++i) {
		cin >> x >> k;
		prim.push_back({x, k});
    pre[i] = k + 1;
		sm = mulmod(sm, mulmod(((binpow(x, k + 1, MOD) - 1) + MOD) % MOD, ((binpow(x - 1, MOD - 2, MOD)) % MOD + MOD) % MOD, MOD), MOD);
		divisors = mulmod(divisors, k + 1, MOD);
	}

  suf[n - 1] = pre[n - 1];
  for (int i{n - 2}; i >= 0; --i) {
    suf[i] = mulmod(suf[i + 1], pre[i], MOD - 1);
  }
  for (int i{1}; i < n; ++i) {
    pre[i] = mulmod(pre[i - 1], pre[i], MOD - 1);
  }

  for (int i{0}; i < n; ++i) {
    int k{prim[i].second}, x{prim[i].first};
    // cout << binpow(x, mulmod(k / ((k & 1) ? 1 : 2), (k + 1) / ((k & 1) ? 2 : 1), MOD - 1), MOD) << " " << mulmod((i ? pre[i - 1] : 1), (i == n - 1 ? 1 : suf[i + 1]), MOD - 1) << "\n";
    prod = mulmod(prod, binpow(binpow(x, mulmod(k / ((k & 1) ? 1 : 2), (k + 1) / ((k & 1) ? 2 : 1), MOD - 1), MOD), mulmod((i ? pre[i - 1] : 1), (i == n - 1 ? 1 : suf[i + 1]), MOD - 1), MOD), MOD);
  }

  cout << divisors << " " << sm << " " << prod << "\n";

  return 0;
}
