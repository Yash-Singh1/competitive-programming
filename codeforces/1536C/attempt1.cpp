#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // We can use DP because we know that if the prefix of n is divisible by k then all prefixes with multiples of k up till n also are divisible by k
  // NVM we need to do range dp and that'll be too slow given bound
  int t;
  cin >> t;

  int n;
  while (t--) {
    cin >> n;
    char str[n];
    for (int i{0}; i < n; ++i) cin >> str[i];
    vector<int> pd(n), pk(n);
    for (int i{0}; i < n; ++i) {
      if (str[i] == 'D') pd[i] = 1;
      else pk[i] = 1;
      if (i != 0) {
        pd[i] += pd[i - 1];
        pk[i] += pk[i - 1];
      }
    }
    vector<int> dp(n, -1);
    dp[0] = 1;
    for (int i{n - 1}; i >= 0; --i) {
      if (dp[i] == -1) {
        for (int j{1}; j <= i + 1; ++j) {
          if ((i + 1) % j == 0) {
            ll ratio1{pd[j - 1]};
            ll ratio2{pk[j - 1]};
            for (int k{j}; k <= i; k += j) {
              if ((pd[k + j - 1] - pd[k - 1]) * ratio2 != (pk[k + j - 1] - pk[k - 1]) * ratio1) {
                goto next;
              } else {
                // if ((k + j) / (j + 1) < dp[k + j - 1]) {
                //   dp[k + j - 1] = (k + j) / (j + 1);
                // }
              }
            }
            dp[i] = (i + 1) / j;
            break;
            next: continue;
          }
        }
      }
    }
    for (int i{0}; i < n; ++i) cout << dp[i] << " ";
    cout << '\n';
  }

  return 0;
}
