#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define LSOne(S) (S & -S)

vector<ll> a(100000);

bool comp(ll x, ll y) {
  return a[x] > a[y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, p, k;
  cin >> n >> p >> k;

  for (ll i{0}; i < n; ++i) cin >> a[i];

  vector<ll> ind(n);
  for (ll i{0}; i < n; ++i) {
    ind[i] = i;
  }
  sort(ind.begin(), ind.end(), comp);

  vector<vector<ll>> bestp(n, vector<ll>(p));
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j < p; ++j) {
      cin >> bestp[i][j];
    }
  }

  vector<vector<pair<ll,ll>>> dp(n+1, vector<pair<ll,ll>>(1<<p));
  for (ll i{1}; i <= n; ++i) {
    for (ll j{0}; j < (1<<p); ++j) {
      dp[i][j] = dp[i - 1][j];
      if (dp[i - 1][j].first + a[ind[i - 1]] > dp[i][j].first && dp[i - 1][j].second < k && __builtin_popcount(j) < i) {
        dp[i][j] = dp[i - 1][j];
        dp[i][j].first += a[ind[i - 1]];
        ++dp[i][j].second;
      }
      ll m{j};
      while (m) {
        if (dp[i - 1][j - LSOne(m)].first + bestp[ind[i - 1]][__builtin_ctz(m)] > dp[i][j].first) {
          dp[i][j].first = dp[i - 1][j - LSOne(m)].first + bestp[ind[i - 1]][__builtin_ctz(m)];
          dp[i][j].second = dp[i - 1][j - LSOne(m)].second;
        }
        m -= LSOne(m);
      }
    }
  }

  cout << dp[n][(1<<p)-1].first << "\n";

  return 0;
}
