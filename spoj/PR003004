#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll mx;
vector<ll> di;

vector<vector<vector<ll>>> dp(19, vector<vector<ll>>(2, vector<ll>(2001, ULLONG_MAX)));

ll dfs(ll pos, int last, int under) {
  if (pos == di.size()) return last;
  if (dp[pos][under][last] != ULLONG_MAX) return dp[pos][under][last];
  int limit = 9;
  if (!under) {
    limit = di[pos];
  }
  ll sm{0};
  for (int i{0}; i <= limit; ++i) {
    ll sme{dfs(pos + 1, last + i, under || (i < limit))};
    sm += sme;
  }
  return (dp[pos][under][last] = sm);
}

void regenmx() {
  di.clear();
  while (mx) {
    di.push_back(mx%10);
    mx /= 10;
  }
  reverse(di.begin(), di.end());
}

void reset() {
  for (int i{0}; i < 19; ++i) {
    for (int j{0}; j < 2; ++j) {
      for (int l{0}; l <= 2000; ++l)
        dp[i][j][l] = ULLONG_MAX;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    ll a, b;
    cin >> a >> b;
    reset();
    mx = b;
    regenmx();
    ll f{dfs(0, 0, 0)};
    ll s=0;
    if (a > 0) {
      reset();
      mx = a - 1;
      regenmx();
      s = dfs(0, 0, 0);
    }
    cout << f-s << "\n";
  }

  return 0;
}
