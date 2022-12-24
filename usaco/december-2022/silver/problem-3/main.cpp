#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  ll a[n][n];
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j < n-i; ++j) {
      cin >> a[i][j]; 
    }
  }

  ll cur[n];
  cur[n - 1] = 1;
  for (ll i{n - 2}; i >= 0; --i) {
    for (ll k{1}; k >= -1; k -= 2) {
      bool didit{1};
      cur[i] = k * (a[i][1] - a[i][0]) + cur[i+1];
      ll mn{cur[i]}, mx{cur[i]};
      for (ll j{i}; j < n; ++j) {
        mn = min(mn, cur[j]);
        mx = max(mx, cur[j]);
        if (mx - mn != a[i][j - i]) {
          didit = 0;
          break;
        }
      }
      if (!didit) continue;
      else break;
    }
  }

  for (int i{0}; i < n; ++i) {
    cout << cur[i] << (i != n-1 ? " " : "");
  }
  cout << "\n";

  return 0;
}
