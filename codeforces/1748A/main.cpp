#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << (int)round(((long double)n)/2) << "\n";
  }

  return 0;
}
