#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;
const ll MAX_N = 255;

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

  string s;
  cin >> s;

  vector<ll> facts(MAX_N + 1, -1);
  vector<ll> inv(MAX_N + 1, -1);
  facts[0] = 1;

  for (ll i{1}; i <= MAX_N; ++i) {
    facts[i] = (facts[i - 1] * i) % MOD;
  }
  inv[MAX_N] = binpow(facts[MAX_N], MOD - 2, MOD);
  for (ll i{MAX_N}; i >= 1; --i) {
    inv[i - 1] = inv[i] * i % MOD;
  }

  ll n{(ll)s.size()};
  vector<vector<ll>> dp(n+1, vector<ll>(n+1));

  for (ll i{0}; i < n; ++i) {
    dp[i + 1][i] = 1;
  }

  for (ll i{n - 1}; i >= 0; --i) {
    for (ll j{i + 1}; j < n; j += 2) {
      for (ll k{i + 1}; k <= j; k += 2) {
        if (s[i] == s[k]) {
          assert(i < n && j < n);
          dp[i][j] += (dp[i + 1][k - 1] * dp[k + 1][j] % MOD) * ((facts[(j - i + 1) / 2] * inv[(k - i + 1) / 2] % MOD) * inv[(j - i + 1) / 2 - (k - i + 1) / 2] % MOD) % MOD;
          dp[i][j] %= MOD;
          // cout << i << " " << j << " " << dp[i][j] << " " << dp[i][j] - orig << " " << k << "\n";
        }
      }
    }
  }

  cout << dp[0][n - 1] << "\n";

  return 0;
}
