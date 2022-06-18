#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k;
  cin >> n;
  cin >> k;
  ++n;
  long long ans{0};
  while (--n) {
    long long x;
    cin >> x;
    if (x % k == 0) {
      ++ans;
    }
  }
  cout << ans;
}
