#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("feast.in", "r", stdin);
  freopen("feast.out", "w", stdout);

  int t, a, b;
  cin >> t >> a >> b;

  vector<vector<bool>> phases(3, vector<bool>(t+1));
  phases[0][0] = 1;
  for (int i{0}; i <= t; ++i) {
    if (phases[0][i]) {
      if (i + a <= t) {
        phases[0][i + a] = 1;
      }
      if (i + b <= t) {
        phases[0][i + b] = 1;
      }
      phases[1][i / 2] = 1;
    }
  }

  for (int i{0}; i <= t; ++i) {
    if (phases[1][i] || phases[2][i]) {
      if (i + a <= t) {
        phases[2][i + a] = 1;
      }
      if (i + b <= t) {
        phases[2][i + b] = 1;
      }
    }
  }

  for (int ans{t}; ans >= 0; --ans) {
    if (phases[2][ans] || phases[0][ans] || phases[1][ans]) {
      cout << ans << "\n";
      break;
    }
  }

  return 0;
}
