#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cowpatibility.in", "r", stdin);
  freopen("cowpatibility.out", "w", stdout);

  int n;
  cin >> n;

  vector<vector<int>> a(n, vector<int>(5));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < 5; ++j) {
      cin >> a[i][j];
    }
    sort(a[i].begin(), a[i].end());
  }

  map<pair<ll,ll>, int> m;
  for (int i{0}; i < n; ++i) {
    pair<ll,ll>p {0,0};
    for (int j{0}; j < 5; ++j) {
      p.first = a[i][j];
      ++m[p];
      for (int k{j+1}; k < 5; ++k) {
        p.first <<= 21;
        p.first += a[i][k];
        ++m[p];
        for (int l{k + 1}; l < 5; ++l) {
          p.first <<= 21;
          p.first += a[i][l];
          ++m[p];
          for (int o{l + 1}; o < 5; ++o) {
            p.second = a[i][o];
            ++m[p];
            if (o == 3) {
              p.second <<= 21;
              p.second += a[i][4];
              ++m[p];
            }
            p.second = 0;
          }
          p.first >>= 21;
        }
        p.first >>= 21;
      }
      p.first = 0;
    }
  }

  int anse{0};
  for (int i{0}; i < n; ++i) {
    int ans{0};
    pair<ll,ll>p {0,0};
    for (int j{0}; j < 5; ++j) {
      p.first = a[i][j];
      ans += m[p];
      for (int k{j+1}; k < 5; ++k) {
        p.first <<= 21;
        p.first += a[i][k];
        ans -= m[p];
        for (int l{k + 1}; l < 5; ++l) {
          p.first <<= 21;
          p.first += a[i][l];
          ans += m[p];
          for (int o{l + 1}; o < 5; ++o) {
            p.second = a[i][o];
            ans -= m[p];
            if (o == 3) {
              p.second <<= 21;
              p.second += a[i][4];
              ans += m[p];
            }
            p.second = 0;
          }
          p.first >>= 21;
        }
        p.first >>= 21;
      }
      p.first = 0;
    }
    anse += n-ans;
  }
  cout << (anse>>1) << "\n";

  return 0;
}
