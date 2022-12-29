#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int i{0}; i < n; ++i) {
    cin >> coins[i];
  }
  sort(coins.begin(), coins.end());

  vector<vector<int>> ways(x+10, vector<int>(n+1));
  ways[0][0] = 1;
  for (int i{0}; i < x; ++i) {
    for (int j{1}; j <= n; ++j) {
      ways[i][j] += ways[i][j - 1];
      ways[i][j] %= MOD;
    }
    for (int j{0}; j < n; ++j) {
      if (i + coins[j] > x) break;
      ways[i + coins[j]][j + 1] += ways[i][j + 1];
      ways[i + coins[j]][j + 1] %= MOD;
    }
  }

  int ans{0};
  for (int i{0}; i < n; ++i) {
    ans += ways[x][i + 1];
    ans %= MOD;
  }

  cout << ans << "\n";

  return 0;
}
