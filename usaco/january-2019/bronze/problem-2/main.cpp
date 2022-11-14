#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("sleepy.in", "r", stdin);
  freopen("sleepy.out", "w", stdout);

  int n;
  cin >> n;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  int ans{0};
  for (int i{n - 2}; i >= 0; --i) {
    if (a[i] > a[i + 1]) {
      ans = i + 1;
      break;
    }
  }

  cout << ans << "\n";

  return 0;
}
