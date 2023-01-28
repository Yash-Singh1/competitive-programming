#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<bool> pos(k + 1);

  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  for (int i{0}; i <= k; ++i) {
    for (auto &x: a) {
      if (i >= x && !pos[i - x]) {
        pos[i] = 1;
      }
    }
  }

  cout << (pos[k] ? "First" : "Second") << "\n";

  return 0;
}
