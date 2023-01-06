#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dist(pair<ll,ll> a, pair<ll,ll> b) {
  return (ll)pow(a.first - b.first, 2) + (ll)pow(a.second - b.second, 2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("checklist.in", "r", stdin);
  freopen("checklist.out", "w", stdout);

  ll h, g;
  cin >> h >> g;

  vector<pair<ll,ll>> ch(h), cg(g);
  for (ll i{0}; i < h; ++i) cin >> ch[i].first >> ch[i].second;
  for (ll i{0}; i < g; ++i) cin >> cg[i].first >> cg[i].second;

  // dp[holsteins finished][guersneys finished] = {cur is holstein, cur is guersney}
  vector<vector<pair<ll,ll>>> dp(h, vector<pair<ll,ll>>(g + 1, {LLONG_MAX, LLONG_MAX}));
  dp[0][0] = {0,0};
  for (ll i{0}; i < h; ++i) {
    for (ll j{0}; j <= g; ++j) {
      if (j == g && i + 1 == h) {
        if (dp[i - 1][j].first != LLONG_MAX) {
          dp[i][j].first = dp[i - 1][j].first + dist(ch[i - 1], ch[i]);
        }
        if (dp[i - 1][j].second != LLONG_MAX) dp[i][j].first = min(dp[i][j].first, dp[i - 1][j].second + dist(ch[i], cg[g - 1]));
      } else {
        if (j != 0) {
          if (dp[i][j - 1].second != LLONG_MAX) dp[i][j].second = dp[i][j - 1].second + dist(cg[j - 1], cg[j - 2]);
          if (dp[i][j - 1].first != LLONG_MAX) {
            dp[i][j].second = min(dp[i][j].second, dp[i][j - 1].first + dist(cg[j - 1], ch[i]));
          }
          // dp[i][j].second = 1;
        }
        if (i != 0) {
          // if (nval < dp[i][j].first) {
          if (dp[i - 1][j].first != LLONG_MAX) dp[i][j].first = dp[i - 1][j].first + dist(ch[i], ch[i - 1]);
            // dp[i][j].second = 0;
          // }
          if (dp[i - 1][j].second != LLONG_MAX) {
            dp[i][j].first = min(dp[i][j].first, dp[i - 1][j].second + dist(ch[i], cg[j - 1]));
          }
        }
      }
    }
  }

  // for (int i{0}; i < h; ++i) {
  //   for (int j{0}; j <= g; ++j) {
  //     cout << dp[i][j].first << "," << dp[i][j].second << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  cout << dp[h - 1][g].first << "\n";

  return 0;
}
