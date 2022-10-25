#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n,s;
  cin >> n >> s;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }

  ll r{0}, sm{0}, tot{0};
  for (ll l{0}; l < n; ++l) {
    while (r < n && sm < s) {
      sm += a[r++];
    }
    if (sm >= s) {
      // cout << l << " " << r <<"\n";
      tot += n - r + 1;
    }
    sm -= a[l];
  }

  cout << tot <<"\n";

  return 0;
}
