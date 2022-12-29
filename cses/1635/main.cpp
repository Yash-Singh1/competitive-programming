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

  vector<int> ways(x+(int)1e6+10);
  ways[0] = 1;
  for (int i{0}; i < x; ++i) {
    for (auto &coin: coins) {
      ways[i + coin] += ways[i];
      ways[i + coin] %= MOD;
    }
  }
  // cout << "\n";

  cout << ways[x] << "\n";

  return 0;
}
