#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, x;
  cin >> n >> x;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }

  ll l{0}, r{0}, sm{0};
  ll tot{0};
  while (l < n) {
    while (r < n && sm < x) {
      sm += a[r];
      ++r;
    }
    if (sm == x) {
      ++tot;
    }
    sm -= a[l];
    ++l;
  }

  cout << tot << "\n";

  return 0;
}
