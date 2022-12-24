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
  for (int i{0}; i < n; ++i) {
    cur[i] = a[0][i];
  }

  for (int i{1}; i < n-1; ++i) {
    for (int j{1}; j < n - i; ++j) {
      if (a[i][j] - a[i][j - 1] != cur[i + j] - cur[i + j - 1]) {
        cur[i + j] = cur[i + j] - abs(a[i][j] - a[i][j - 1]);
      }
    }
  }

  for (int i{0}; i < n; ++i) {
    cout << cur[i] << " ";
  }
  cout << "\n";

  return 0;
}
