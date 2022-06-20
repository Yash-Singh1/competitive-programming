#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  ++t;
  while (--t) {
    int n, c;
    cin >> n >> c;
    for (int i{0}; i < n; ++i) {
      int x;
      cin >> x;
      c -= x;
    }
    if (c < 0) {
      cout << "No" << "\n";
    } else {
      cout << "Yes" << "\n";
    }
  }
}
