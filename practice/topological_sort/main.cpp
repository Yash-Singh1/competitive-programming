/**
  Implementation of topological sort
  As mentioned in Section 1.4 Greedy Algorithm Text in USACO Training Gateway
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  bool v[n][n];
  for (int i{0}; i < n; ++i) {
      for (int j{0}; j < n; ++j) {
          v[i][j] = 0;
      }
  }
  int k;
  cin >> k;
  while (k--) {
    int a, b;
    cin >> a >> b;
    v[a][b] = 1;
  }
  map<int, bool> included;
    string ans;
  while (ans.size() < n) {
      int origin{-1};
      for (int i{0}; i < n; ++i) {
        if (included[i]) continue;
        int tot{0};
        for (int j{0}; j < n; ++j) {
            if (v[i][j]) ++tot; 
        }
        if (tot == 0) {
          origin = i;
            included[origin] = 1;
          ans = std::to_string(origin) + ans;
          for (int j{0}; j < n; ++j) {
            v[j][i] = 0;
          }
        }
      }
      if (origin == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
  }
  cout << ans << endl;
}
