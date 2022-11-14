#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (a == 0 || b == 0) {
        return max(a, b);
    }
    return gcd(max(a, b) % min(a, b), min(a, b));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;
  cout << gcd(a, b) << "\n";

  return 0;
}
