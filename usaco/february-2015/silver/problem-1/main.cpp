#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
      ans %= m;
    }
    ++pow;
    curp = mulmod(curp, curp, m);
    curp %= m;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);

  string s, t;
  cin >> s >> t;

  vector<ll> powb(s.size()), powi(s.size());
  powb[0] = 1;
  for (int i{1}; i < (int)s.size(); ++i) {
    powb[i] = mulmod(powb[i - 1], 26, MOD);
  }
  powi[s.size() - 1] = binpow(powb[s.size() - 1], MOD - 2, MOD);
  for (int i{(int)s.size() - 2}; i >= 0; --i) {
    powi[i] = mulmod(powi[i + 1], 26, MOD);
  }
  ll hast{0};
  for (int i{0}; i < (int)t.size(); ++i) {
    hast += mulmod((t[i] - 'a' + 1), powb[i], MOD);
    hast %= MOD;
  }

  vector<ll> rolling(s.size());
  int j{0};
  string p = s;
  for (int i{0}; i < (int)s.size(); ++i) {
    rolling[j] = ((j == 0 ? 0 : rolling[j - 1]) + ((s[i] - 'a' + 1) * powb[j])) % MOD;
    p[j] = s[i];
    if (j >= (int)t.size() - 1) {
      if (mulmod((rolling[j] - (j == (int)t.size()-1 ? 0 : rolling[j - (int)t.size()]) + MOD) % MOD, powi[j - t.size() + 1], MOD) == hast) {
        j -= t.size();
      }
    }
    ++j;
  }

  for (int i{0}; i < j; ++i) {
    cout << p[i];
  }
  cout << "\n";

  return 0;
}
