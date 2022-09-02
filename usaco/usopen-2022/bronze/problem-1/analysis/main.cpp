#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int last{-1}, ans{0};
  for (int i{0}; i < n; i += 2) {
    char x, y;
    cin >> x >> y;
    // Prevent _s
    if (x != y) {
      if (x == 'G') {
        if (last != 1) {
          ++ans;
        }
        last = 1;
      }
      else {
        if (last != 0) {
          ++ans;
        }
        last = 0;
      }
    }
  }
  if (last == 0) {
    --ans;
  }
  cout << ans;
}
