#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int x{0};
  int a;
  for (int i{1}; i < n; ++i) {
    cin >> a;
    x ^= a;
  }
  for (int i{1}; i <= n; ++i) {
    x ^= i;
  }

  cout << x << "\n";

  return 0;
}
