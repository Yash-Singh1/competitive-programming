#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int a[n];
  int memo[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    memo[i] = -1;
  }
  for (int i{n - 1}; i >= 0; --i) {
    if (i == n - 1) {
        memo[i] = 0;
        continue;
    }
    int ans1{INT_MAX};
    int ans2{INT_MAX};
    if (n > i + 1) {
        ans1 = memo[i + 1] + abs(a[i] - a[i + 1]);
    }
    if (n > i + 2) {
        ans2 = memo[i + 2] + abs(a[i] - a[i + 2]);
    }
    int ans{min(ans1, ans2)};
    memo[i] = ans;
  }
  cout << memo[0];
}
