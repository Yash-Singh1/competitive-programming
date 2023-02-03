#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<int> skill(n);
  for (int i{0}; i < n; ++i) {
    cin >> skill[i];
  }
  sort(skill.begin(), skill.end());

  vector<vector<ll>> dp1(51, vector<ll>(10001));
  vector<vector<ll>> dp2(51, vector<ll>(10001));
  dp1[0][5000] = 1;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j <= 50; ++j) {
      for (int k{0}; k <= 10000; ++k) {
        if (!dp1[j][k]) continue;
        dp2[j][k] = (dp1[j][k] * (j + 1) + dp2[j][k]) % MOD;
        if (k >= skill[i] && j < 50) dp2[j + 1][k - skill[i]] = (dp2[j + 1][k - skill[i]] + dp1[j][k]) % MOD;
        if (k + skill[i] <= 10000 && j) dp2[j - 1][k + skill[i]] = (dp1[j][k] * j + dp2[j - 1][k + skill[i]]) % MOD;
        dp1[j][k] = 0;
      }
    }
    swap(dp1, dp2);
  }

  ll ans{0};
  for (int i{5000}; i <= 5000+x; ++i) {
    ans += dp1[0][i];
    ans %= MOD;
  }

  cout << ans << "\n";

  return 0;
}
