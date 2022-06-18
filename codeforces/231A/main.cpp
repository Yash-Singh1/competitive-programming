#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int ans{0};
  for (int i{0}; i < n; ++i) {
    int a{0};
    int x;
    for (int i{0}; i < 3; ++i) {
      cin >> x;
      if (x) {
        ++a;
      }
    }
    if (a >= 2) {
      ++ans;
    }
  }
  cout << ans;
}
