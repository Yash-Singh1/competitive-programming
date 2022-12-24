#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;

  bool prime[5000001];
  for (ll i{0}; i <= 5000000; ++i) {
    prime[i] = 1;
  }
  for (ll j{2}; j <= sqrt(5000000); ++j) {
    if (!prime[j]) continue;
    for (ll k{j*j}; k <= 5000000; k += j) {
      prime[k] = 0;
    }
  }

  while (t--) {
    ll n;
    cin >> n;

    ll a[n];
    for (ll i{0}; i < n; ++i) {
      cin >> a[i];
    }
    bool john{0};
    ll fourfound{LLONG_MAX};
    ll fourfoundi{LLONG_MAX};
    ll foursuccess{LLONG_MAX};
    ll foursuccessi{-1};

    for (ll i{0}; i < n; ++i) {
      if (a[i] % 4 == 0) {
        fourfound = min(fourfound, a[i] / 4);
        fourfoundi = i;
      }
      john = 1;
      if (prime[a[i]]) {
        foursuccess = 0;
      } else {
        foursuccess = min(foursuccess, a[i] / 4);
      }
      foursuccessi = i;
      // for (ll j{a[i]}; j > 0; j -= 4) {
      //   if (j != a[i] && a[i] - j > fourfound) break;
      //   if (prime[j]) {
      //     john = 1;
      //     foursuccess = min(foursuccess, (a[i] - j) / 4);
      //   }
      // }
    }

    if (john && foursuccess <= fourfound && (foursuccess != fourfound || foursuccessi < fourfoundi)) {
      cout << "Farmer John\n";
    } else {
      cout << "Farmer Nhoj\n";
    }
  }

  return 0;
}
