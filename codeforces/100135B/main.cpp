#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lepus.in", "r", stdin);
  freopen("lepus.out", "w", stdout);

  int n;
  cin >> n;

  vector<char> line(n);
  for (int i{0}; i < n; ++i) {
    cin >> line[i];
  }

  vector<int> dp(n);
  vector<int> movement(3);
  vector<bool> visited(n);
  for (int i{1}; i < n; ++i) {
    visited[i] = 0;
  }
  visited[0] = 1;
  movement[0] = 1;
  movement[1] = 3;
  movement[2] = 5;
  for (int i{0}; i < n - 1; ++i) {
    if (!visited[i]) continue;
    for (int j{0}; j < 3; ++j) {
      if (i + movement[j] >= n || line[i + movement[j]] == 'w') {
        continue;
      }
      visited[i + movement[j]] = 1;
      dp[i + movement[j]] = max(dp[i + movement[j]], dp[i] + (line[i + movement[j]] == '"' ? 1 : 0));
    }
  }

  cout << (visited[n-1] ? dp[n - 1] : -1) << "\n";

  return 0;
}
