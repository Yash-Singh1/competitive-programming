#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  ++t;
  while (--t) {
    int x, y, k, n;
    cin >> x >> y >> k >> n;
    x -= y;
    bool lucky{0};
    for (int i{0}; i < n; ++i) {
      int c, p;
      cin >> p >> c;
      if (p >= x && c <= k) {
        lucky = 1;
      }
    }
    if (lucky) {
      cout << "LuckyChef" << endl;
    } else {
      cout << "UnluckyChef" << endl;
    }
  }
}
