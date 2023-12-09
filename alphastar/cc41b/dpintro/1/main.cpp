#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n <= 2) {
    cout << n << '\n';
    return 0;
  }

  int b{1}, c{2}, d{2};
  for (int i{4}; i <= n; ++i) {
    c = d;
    d = d + b;
    b = c;
  }
  cout << d << '\n';

  return 0;
}
