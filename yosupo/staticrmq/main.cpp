#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) (S & -S)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<vector<int>> table(n, vector<int>(20, INT_MAX));
  for (int i{0}; i < n; ++i) {
    cin >> table[i][0];
  }

  for (int i{1}; i < 20; ++i) {
    for (int j{0}; j < n; ++j) {
      if (table[j][i - 1] == INT_MAX || j + (1<<(i-1)) >= n) continue;
      table[j][i] = min(table[j][i - 1], table[j + (1<<(i-1))][i - 1]);
    }
  }

  int a, b;
  while (q--) {
    cin >> a >> b;
    int d{b-a}, cur{a};
    int ans{INT_MAX};
    while (d) {
      ans = min(ans, table[cur][__builtin_ctz(d)]);
      cur += LSOne(d);
      d -= LSOne(d);
    }
    cout << ans << "\n";
  }

  return 0;
}
