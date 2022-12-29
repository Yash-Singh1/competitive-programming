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

  vector<vector<int>> ways(n+1, vector<int>(x+1));
  ways[0][0] = 1;
  for (int i{1}; i <= n; ++i) {
    for (int j{0}; j <= x; ++j) {
      ways[i][j] = ways[i - 1][j];
      if (j - coins[i-1] >= 0) {
        (ways[i][j] += ways[i][j - coins[i - 1]]) %= MOD;
      }
    }
  }

  cout << ways[n][x] << "\n";

  return 0;
}
