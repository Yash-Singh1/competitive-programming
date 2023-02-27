#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<vector<ll>>> dp(19, vector<vector<ll>>(19, vector<ll>(2, -1)));
ll mx;
vector<int> di;
ll n, m, d, k;

ll dfs(ll x, ll y, int under) {
  if (x == di.size()) return (y == k ? 1 : 0);
  if (dp[x][y][under] != -1) return dp[x][y][under];
  int limit{9};
  if (!under) {
    limit = di[x];
  }
  ll sm{0};
  for (int i{0}; i <= limit; ++i) {
    sm += dfs(x + 1, y + (i == d ? 1 : 0), (under ? under : i != limit));
  }
  return (dp[x][y][under] = sm);
}

void regenmx() {
  di.clear();
  while (mx > 0) {
    di.push_back(mx%10);
    mx/=10;
  }
  reverse(di.begin(), di.end());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k >> d;

  mx = m;
  regenmx();
  ll f{dfs(0, 0, 0)};
  for (int i{0}; i <= 18; ++i) {
    for (int j{0}; j <= k; ++j) {
      for (int l{0}; l < 2; ++l) {
        dp[i][j][l] = -1;
      }
    }
  }
  mx = n-1;
  regenmx();
  cout << f-dfs(0,0,0) << "\n";

  return 0;
}
