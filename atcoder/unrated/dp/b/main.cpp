#include <bits/stdc++.h>

using namespace std;

  int n;
  int k;
int a[100005];
int memo[100005];

int sol(int i) {
    if (i == n - 1) {
        return 0;
    }
    if (memo[i] != -1) {
        return memo[i];
    }
    int mini{INT_MAX};
    for (int j{1}; j <= k; ++j) {
        if (n > i + j) {
            int ans1 = sol(i + j) + abs(a[i] - a[i + j]);
            if (ans1 < mini) {
                mini = ans1;
            }
        }
    }
    memo[i] = mini;
    return mini;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    memo[i] = -1;
  }
  cout << sol(0);
}
