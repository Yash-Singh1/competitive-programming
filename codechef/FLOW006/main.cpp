#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  ++t;
  while (--t) {
    int a;
    cin >> a;
    int ans{0};
    while (a > 0) {
      ans += a % 10;
      a /= 10;
    }
    cout << ans << endl;
  }
}
