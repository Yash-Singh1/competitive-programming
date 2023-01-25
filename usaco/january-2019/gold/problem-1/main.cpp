#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll mulmod(ll a, ll b, ll m) {
  return (ll)(((__int128)a * (__int128)b) % m);
}

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

  vector<pii> words(n);
  for (int i{0}; i < n; ++i) {
    cin >> words[i].first >> words[i].second;
    --words[i].second;
  }

  vector<vector<ll>> dp(k+1, vector<ll>(n));
  vector<ll> dps(k + 1);
  dps[0] = 1;
  for (int i{0}; i <= k; ++i) {
    if (i != 0) {
      for (int j{0}; j < n; ++j) {
        dps[i] += dp[i][j];
        dps[i] %= MOD;
      }
    }
    for (auto &word: words) {
      if (i + word.first > k) continue;
      dp[i + word.first][word.second] += dps[i];
      dp[i + word.first][word.second] %= MOD;
    }
  }

  map<char, int> mf;
  char x;
  for (int i{0}; i < m; ++i) {
    cin >> x;
    ++mf[x];
  }

  ll ans{1};
  for (auto it = mf.begin(); it != mf.end(); it = next(it)) {
    ll sm{0};
    for (int i{0}; i < n; ++i) {
      sm += binpow(dp[k][i], it->second, MOD);
      sm %= MOD;
    }
    ans = mulmod(ans, sm, MOD);
  }

  cout << ans << "\n";

  return 0;
}
