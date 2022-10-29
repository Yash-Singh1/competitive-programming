// TLE on USACO Guide Group, but all TCs AC on USACo
// probably judge related, this is best I can go

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct pair_hash {
    inline size_t operator()(const pair<char,pair<char,char>> v) const {
        return (v.first | v.second.first<<8)<<8 | v.second.second;
    }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);

  ll n, m;
  cin >> n >> m;

  string spotty[n];
  string plain[n];

  for (ll i{0}; i < n; ++i) {
    cin >> spotty[i];
  }

  for (ll i{0}; i < n; ++i) {
    cin >> plain[i];
  }

  ll tot{0};
  for (ll i{0}; i < m; ++i) {
    for (ll j{i + 1}; j < m; ++j) {
      for (ll k{j + 1}; k < m; ++k) {
        bool match{1};
        unordered_set<pair<char,pair<char,char>>,pair_hash>ma;
        for (ll l{0}; l < n; ++l) {
          ma.insert({spotty[l][i],{spotty[l][k],spotty[l][j]}});
        }
        for (ll l{0}; l < n; ++l) {
          if (ma.find({plain[l][i],{plain[l][k],plain[l][j]}}) != ma.end()) {
            match=0;
          }
        }
        if (match) ++tot;
      }
    }
  }

  cout << tot << "\n";

  return 0;
}
