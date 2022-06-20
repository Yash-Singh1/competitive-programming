#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  ++t;
  while (--t) {
    int n, k;
    int tot{0};
    cin >> n >> k;
    k %= 7;
    k = 7 - k;
    k %= 7;
    for (int i{0}; i < n; ++i) {
      int x;
      cin >> x;
      if (x % 7 == k) {
        ++tot;
      }
    }
    cout << tot << endl;
  }
}
