#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> stage_order(m);
  for (int i{0}; i < m; ++i) {
    cin >> stage_order[i];
    --stage_order[i];
  }

  vector<vector<int>> g(n, vector<int>(n));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> g[i][j];
    }
  }

  for (int k{0}; k < n; ++k) {
    for (int i{0}; i < n; ++i) {
      for (int j{0}; j < n; ++j) {
        if (g[i][k] + g[k][j] < g[i][j]) {
          g[i][j] = g[i][k] + g[k][j];
        }
      }
    }
  }

  int sm{0};
  for (int i{1}; i < m; ++i) {
    sm += g[stage_order[i-1]][stage_order[i]];
  }

  cout << sm << '\n';

  return 0;
}
