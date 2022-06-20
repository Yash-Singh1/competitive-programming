#include <bits/stdc++.h>

using namespace std;

vector<int> dp(100005, 0);

int rec(int n) {
    if (n <= 1) {
        return 1;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    int tot{0};
    for (int i{1}; i <= 6 && n >= i; ++i) {
        tot += rec(n - i);
        tot %= 1000000007;
    }
    dp[n] = tot;
    return tot;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  cout << rec(n);
}
