#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(19, vector<ll>(4)));
ll mx;
vector<ll> di;

void reset() {
  for (int i{0}; i < 2; ++i) {
    for (int j{0}; j <= 18; ++j) {
      for (int k{0}; k < 4; ++k) {
        dp[i][j][k] = -1;
      }
    }
  }
}

void regenmx() {
  di.clear();
  while (mx) {
    di.push_back(mx%10);
    mx /= 10;
  }
  reverse(di.begin(), di.end());
}

ll dfs(int under, int pos, int k) {
  if (k == 4) return 0;
  if (pos == di.size()) return 1;
  if (dp[under][pos][k] != -1) return dp[under][pos][k];
  int limit = 9;
  if (!under) {
    limit = di[pos];
  }
  ll sm{0};
  for (int i{0}; i <= limit; ++i) {
    sm += dfs(under || (i < limit), pos + 1, k + (i != 0));
  }
  return (dp[under][pos][k] = sm);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  ll a, b;
  while (t--) {
    cin >> a >> b;
    reset();
    mx = b;
    regenmx();
    ll f{dfs(0, 0, 0)};
    reset();
    mx = a-1;
    regenmx();
    cout << f-dfs(0, 0, 0) << "\n";
  }

  return 0;
}
