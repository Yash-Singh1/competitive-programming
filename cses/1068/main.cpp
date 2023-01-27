#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  while (n != 1) {
    cout << n << " ";
    if (n & 1) {
      n *= 3; ++n;
    } else {
      n >>= 1;
    }
  }
  cout << "1\n";

  return 0;
}
