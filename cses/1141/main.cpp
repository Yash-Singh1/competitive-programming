#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  int r{0};
  unordered_map<int,int> f;
  int ans{0};
  for (int l{0}; l < n; ++l) {
    while (r < n) {
      if (f[a[r]] >= 1) break;
      ++f[a[r]];
      ++r;
    }
    ans = max(ans, r - l);
    --f[a[l]];
  }

  cout << ans << "\n";

  return 0;
}
