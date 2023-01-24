#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;

ll mulmod(ll a, ll b) {
  a %= MOD;
  b %= MOD;
  return (ll)(((__int128)a * (__int128)b) % MOD);
}

vector<vector<int>> g;
vector<vector<ll>> dp;

void dfs(int u, int p) {
  for (auto &v: g[u]) {
    if (v != p) {
      dfs(v, u);
      dp[u][0] = mulmod(dp[u][0], dp[v][1] + dp[v][2]);
      dp[u][1] = mulmod(dp[u][1], dp[v][0] + dp[v][2]);
      dp[u][2] = mulmod(dp[u][2], dp[v][0] + dp[v][1]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("barnpainting.in", "r", stdin);
  freopen("barnpainting.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  g.resize(n);
  int x, y;
  for (int i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dp.assign(n, vector<ll>(3, 1LL));
  for (int i{0}; i < k; ++i) {
    cin >> x >> y;
    --x;
    for (int j{1}; j <= 3; ++j) {
      if (j != y) {
        dp[x][j - 1] = 0;
      }
    }
  }

  dfs(0, -1);
  cout << (dp[0][0] + dp[0][1] + dp[0][2]) % MOD << "\n";

  return 0;
}
