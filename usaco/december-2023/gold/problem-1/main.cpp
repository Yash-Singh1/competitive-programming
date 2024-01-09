#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<vector<ll>> reqpar(n, vector<ll>(n, 0));
  string x;
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j < n; ++j) reqpar[i][j] = 0;
  }
  for (ll i{0}; i < n-1; ++i) {
    cin >> x;
    assert((int)x.size() == n-i-1);
    for (ll j{i+1}; j < n; ++j) {
      reqpar[i][j] = (x[j-i-1] == '1' ? 1 : 0);
    }
  }

  vector<vector<ll>> par(n, vector<ll>(n, 0));
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j < n; ++j) {
      par[i][j] = 0;
    }
  }
  ll ans{0};
  for (ll i{n-2}; i >= 0; --i) {
    ll nx{-1};
    for (ll j{i+1}; j < n; ++j) {
      if (reqpar[i][j]) {
        // cout << i << ' ' << j << '\n';
        par[i][j] = 1;
        nx = j;
        ++ans;
        break;
      }
    }
    // assert(nx != -1);
    if (nx != -1) {
      for (ll j{nx+1}; j < n; ++j) {
        if (reqpar[nx][j]) {
          par[i][j] = 1;
        }
      }
    }
  }

  for (ll l{0}; l < n; ++l) {
    for (ll i{0}; i < n-1; ++i) {
      for (ll j{i+1}; j < n; ++j) {
        // if (i == 0 && j == 4) {
        //   cout << "SPEC: " << reqpar[i][j] << ' ' << par[i][j] << '\n';
        // }
        if (reqpar[i][j] != par[i][j]) {
          // cout << i << ' ' << j << '\n';
          ++ans;
          par[i][j] = reqpar[i][j];
          for (ll k{j+1}; k < n; ++k) {
            // if (j == 3 && k == 4) {
            //   cout << "SPEC2: " << par[i][j] << ' ' << par[j][k] << '\n';
            // }
            par[i][k] = ((par[i][j] * par[j][k]) + par[i][k]) % 2;
            // if ((par[i][j] && par[j][k]) && par[i][k]) {
            //   par[i][k] = 0;
            // } else {
            //   par[i][k] = (par[i][j] && par[j][k]) ? 1 : (par[i][k] == 1 ? 1 : 0);
            // }
          }
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
