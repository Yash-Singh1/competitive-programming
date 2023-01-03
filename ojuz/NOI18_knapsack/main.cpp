#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// We can reduce k to s / w because that's the max # of times it can be used
// We can arrange each weight into s / w values in descending order of value beacuse the rest can't be used and will be not optimal to use
// According to the timecompcheck.cpp, that's 15518 items and max weight of 2000 making O(ns) about 4e7

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll s, n;
  cin >> s >> n;

  map<ll,ll> valsf;
  map<ll, map<ll,ll>> vall;
  ll v, w, k;
  map<ll,ll> vali;
  map<ll,ll> itoval;
  ll curvalj{0};
  for (ll i{0}; i < n; ++i) {
    cin >> v >> w >> k;
    if (vali.find(w) == vali.end()) {
      vali[w] = curvalj;
      itoval[curvalj] = w;
      ++curvalj;
    }
    k = min(k, s);
    if (k > 0) {
      valsf[w] += k;
      vall[w][v] = k;
    }
  }

  vector<vector<ll>> dp(curvalj + 1, vector<ll>(s+1, -1));
  dp[0][s] = 0;
  ll ans{0};
  for (ll i{0}; i < curvalj; ++i) {
    for (ll j{s}; j >= 0; --j) {
      if (dp[i][j] != -1) {
        if (i != 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        // cout << "raninhere " << i << " " << j << " " << dp[i][j] << "\n";
        ll tot{0}, totv{0};
        ll placeholder;
        // cout << "dump " << vall[itoval[i]].size() << "\n";
        for (auto it = vall[itoval[i]].rbegin(); it != vall[itoval[i]].rend(); it = next(it)) {
          // if (i == 1) cout << it->first << " " << it->second << "\n";
          for (ll l{0}; l < it->second; ++l) {
            ++tot;
            totv += it->first;
            if ((itoval[i] * tot) > j) {
              goto end;
            }
            dp[i + 1][j - (itoval[i] * tot)] = max(dp[i + 1][j - (itoval[i] * tot)], dp[i][j] + totv);
          }
        }
        end: placeholder = 1;
        // if (j == 1) {
        //   ans = max(dp[i + 1][j], ans);
        // }
      }
      ans = max(dp[i + 1][j], ans);
    }
  }

  cout << ans << "\n";

  return 0;
}
