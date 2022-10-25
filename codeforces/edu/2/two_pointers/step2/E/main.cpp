#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, s;

  cin >> n >>s;

  ll a[n];
  for (ll i{0}; i < n; ++i) {
    cin >> a[i];
  }

  map<ll,ll>freq;
  ll l{0};
  ll tot{0};
  for (ll r{0}; r < n; ++r) {
    ++freq[a[r]];
    while (l < r && (ll)freq.size() > s) {
      --freq[a[l]];
      if (freq[a[l]] == 0) {
        freq.erase(a[l]);
      }
      ++l;
    }
    if ((ll)freq.size() <= s) {
      tot += r - l + 1;
    }
  }

  cout << tot << "\n";

  return 0;
}
