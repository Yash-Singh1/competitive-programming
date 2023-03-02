#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  vector<int> fact(9);
  fact[0] = 1;
  for (int i{1}; i < 9; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  vector<int> dp(100001, INT_MAX);
  dp[0] = 0;
  for (int i{0}; i < 9; ++i) {
    for (int j{0}; j < 100000; ++j) {
      if (fact[i] + j > 100000) continue;
      dp[fact[i] + j] = min(dp[fact[i] + j], dp[j] + 1);
    }
  }
  while (getline(cin, s) && s.size()) {
    cout << dp[stoi(s)] << "\n";
    s = "";
  }

  return 0;
}
