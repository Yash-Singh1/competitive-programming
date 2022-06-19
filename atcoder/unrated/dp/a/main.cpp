#include <bits/stdc++.h>

using namespace std;

  int n;
int a[100005];
int memo[100005];

int sol(int i) {
    if (i == n - 1) {
        return 0;
    }
    if (memo[i] != -1) {
        return memo[i];
    }
    int ans1{INT_MAX};
    int ans2{INT_MAX};
    if (n > i + 1) {
        ans1 = sol(i + 1) + abs(a[i] - a[i + 1]);
    }
    if (n > i + 2) {
        ans2 = sol(i + 2) + abs(a[i] - a[i + 2]);
    }
    memo[i] = min(ans1, ans2);
    return min(ans1, ans2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    memo[i] = -1;
  }
  cout << sol(0);
}
