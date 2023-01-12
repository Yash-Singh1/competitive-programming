#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, q;
  cin >> n >> q;

  ll p[n];
  for (ll i{0LL}; i < n; ++i) {
    cin >> p[i];
    if (i != 0LL) p[i] += p[i - 1];
  }

  ll a, b;
  for (ll i{0LL}; i < q; ++i) {
    cin >> b >> a;
    --a; --b;
    cout << p[a] - (b == 0LL ? 0LL : p[b - 1]) << "\n";
  }

  return 0;
}
