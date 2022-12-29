#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
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
    int mini{INT_MAX};
    for (int j{1}; j <= k; ++j) {
        if (n > i + j) {
            int ans1 = memo[i + j] + abs(a[i] - a[i + j]);
            if (ans1 < mini) {
                mini = ans1;
            }
        }
    }
    memo[i] = mini;
  }
  cout << memo[0];
}
