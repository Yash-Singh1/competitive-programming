#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }
  sort(a,a+n);

  int r{0}, ans{0};
  for (int l{0}; l < n; ++l) {
    while (r < n && a[l] + k >= a[r]) {
      ++r;
    }
    ans = max(ans,r-l);
  }

  cout << ans << "\n";

  return 0;
}
