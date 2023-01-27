#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cowrun.in", "r", stdin);
  freopen("cowrun.out", "w", stdout);

  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i{0}; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  // Range dp[side (0 = left, 1 = right)][left (extension to left)][right (extension to right)]
  ll left{(ll)(upper_bound(a.begin(), a.end(), 0) - a.begin())};
  ll right{n - left};

  vector<ll> l(left+1), r(right+1);
  for (ll i{left-1}; i >= 0; --i) {
    l[left - 1 - i + 1] = a[i];
  }
  for (ll i{left}; i < n; ++i) {
    r[i - left + 1] = a[i];
  }
  // for (ll i{0}; i <= left; ++i) cout << l[i] << " ";
  // cout << '\n';
  // for (ll i{0}; i <= right; ++i) cout << r[i] << " ";
  // cout << '\n';
  vector<vector<vector<pll>>> dp(left + 1, vector<vector<pll>>(right + 1, vector<pll>(2, {INT_MAX, INT_MAX})));
  dp[0][0][0] = {0, 0};
  dp[0][0][1] = {0, 0};
  for (ll i{0}; i <= left; ++i) {
    for (ll j{0}; j <= right; ++j) {
      if (i == 0) {
        
      }
      for (ll k{0}; k < 2; ++k) {
        if (dp[i][j][k].first == LLONG_MAX) continue;
        if (i != left) {
          ll newdist{(n - (i + j)) * (k == 0 ? abs(l[i] - l[i + 1]) : abs(r[j] - l[i + 1]))};
          if (dp[i][j][k].second + newdist < dp[i + 1][j][0].second) {
            dp[i + 1][j][0] = {newdist, dp[i][j][k].second + newdist};
          }
          // dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + (k == 0 ? (l[i] - l[i + 1]) : (r[j] - l[i + 1])));
        }
        if (j != right) {
          ll newdist{(n - (i + j)) * (k == 0 ? abs(r[j + 1] - l[i]) : abs(r[j + 1] - r[j]))};
          if (dp[i][j][k].second + newdist < dp[i][j + 1][1].second) {
            dp[i][j + 1][1] = {newdist, dp[i][j][k].second + newdist};
          }
          // dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + (k == 0 ? (r[j + 1] - l[i]) : (r[j + 1] - r[j])));
        }
      }
    }
  }

  // cout << "\n";
  // for (ll i{0}; i <= left; ++i) {
  //   for (ll j{0}; j <= right; ++j) {
  //     for (ll k{0}; k < 2; ++k) {
  //       cout << dp[i][j][k].second; if (k == 0) cout << ',';
  //     }
  //     cout << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";
  cout << min(dp[left][right][0].second, dp[left][right][1].second) << "\n";

  return 0;
}
