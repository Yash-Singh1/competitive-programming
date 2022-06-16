#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  for (int i{1}; i <= n; ++i) {
    char x;
    cin >> x;
    if (k == i) {
      x += 32;
    }
    cout << x;
  }
}
