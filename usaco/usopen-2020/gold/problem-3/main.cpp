#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<bool> primes(n+1, true);
  vector<int> prime;
  for (int i{2}; i <= n; ++i) {
    if (primes[i]) {
      prime.push_back(i);
      // dp[i] = i;
      for (int j{i*i}; j <= n; j += i) {
        if (primes[j]) primes[j] = 0;
      }
    }
  }

  vector<vector<ll>> dp(prime.size()+1, vector<ll>(n+1));
  ll sm{0};
  // for offsets
  for (int i{0}; i <= n; ++i) dp[0][i] = 1;
  for (int i{0}; i < prime.size(); ++i) {
    for (int j{0}; j <= n; ++j) {
      dp[i+1][j] += dp[i][j];
      dp[i+1][j] %= m;
      int curp{prime[i]};
      while (j+curp<=n) {
        dp[i+1][j+curp] += (dp[i][j]*curp);
        dp[i+1][j+curp] %= m;
        curp *= prime[i];
      }
    }
  }

  cout << dp[prime.size()][n] << "\n";

  return 0;
}
