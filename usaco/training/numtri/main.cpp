/*
ID: saiansh1
LANG: C++
TASK: numtri
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("numtri.in", "r", stdin);
  freopen("numtri.out", "w", stdout);

  int n;
  cin >> n;

  int a[n][n];

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < i + 1; ++j) {
      cin >> a[i][j];
    }
  }
  
  int dp[n][n];
  for (int i{0}; i < n; ++i) {
    dp[n-1][i] = a[n-1][i];
  }

  for (int i{n-2}; i >= 0; --i) {
    for (int j{0}; j < i + 1; ++j) {
      dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + a[i][j];
    }
  }

  cout << dp[0][0] << "\n";
}
