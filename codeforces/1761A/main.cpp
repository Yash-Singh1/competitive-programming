#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  int n, a, b;
  while (t--) {
    cin >> n >> a >> b;

    if ((a == n && b == n) || (a + b <= n-2)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}
