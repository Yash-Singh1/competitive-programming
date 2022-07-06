#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  ++t;
  while (--t) {
    int x, y;
    cin >> x >> y;
    cout << max(y - x, 0) << "\n";
  }
}
