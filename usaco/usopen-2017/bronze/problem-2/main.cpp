#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  string spotty[n];
  string plain[n];

  for (int i{0}; i < n; ++i) {
    cin >> spotty[i];
  }

  for (int i{0}; i < n; ++i) {
    cin >> plain[i];
  }

  int tot{0};
  for (int i{0}; i < m; ++i) {
    bool match{1};
    for (int j{0}; j < n; ++j) {
      for (int k{0}; k < n; ++k) {
        if (spotty[j][i] == plain[k][i]) {
          match = 0;
        }
      }
    }
    if (match) ++tot;
  }

  cout << tot << "\n";

  return 0;
}
