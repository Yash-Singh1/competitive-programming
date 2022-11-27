#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t, k;
  cin >> n >> t >> k;

  int l{1}, r{n}, ans{-1};
  int s;
  while (l <= r) {
    int m{(l+r)/2};
    cout << "? " << 1 << " " << m << "\n";
    cout.flush();
    cin >> s;
    s = m - s;
    if (s < k) {
      l = m+1;
    } else if (s == k) {
      ans = m;
      r = m-1;
    } else {
      r = m-1;
    }
  }

  cout << "! " << ans << "\n";

  return 0;
}
