#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lazy.in", "r", stdin);
  freopen("lazy.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  int a[n][n];
  int p[n][n];

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> a[i][j];
      p[i][j] = a[i][j];
    }
  }

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (i != 0) {
        p[i][j] += p[i - 1][j];
      }
      if (j != 0) {
        p[i][j] += p[i][j - 1];
      }
      if (i != 0 && j != 0) {
        p[i][j] -= p[i - 1][j - 1];
      }
    }
  }

  // for (int i{0}; i < n; ++i) {
  //   for (int j{0}; j < n; ++j) {
  //     cout << p[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  int ans{-1};
  int reached{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      reached = 0;
      for (int l{j - k}; l <= j + k; ++l) {
        if (l <n && l >= 0) {
          // k - abs(l-j) = amount wrap around i point
          // if (i == 2 && j == 2) cout << l << " " << p[min(n-1, i + (k - abs(l - j)))][l] - ((i - (k - abs(l - j))) <= 0 ? 0 : p[(i - (k - abs(l - j))) - 1][l]) - (l ? p[min(n-1, i + (k - abs(l - j)))][l - 1] : 0) << "\n";
          reached += p[min(n-1, i + (k - abs(l - j)))][l] - ((i - (k - abs(l - j))) <= 0 ? 0 : p[(i - (k - abs(l - j))) - 1][l]) - (l ? p[min(n-1, i + (k - abs(l - j)))][l - 1] : 0) + ((i - (k - abs(l - j))) <= 0 || l == 0 ? 0 : p[(i - (k - abs(l - j))) - 1][l-1]);
        }
      }
      // if (reached > ans) cout << i << " " << j << "\n";
      ans = max(ans, reached);
    }
  }

  cout << ans << "\n";

  return 0;
}
