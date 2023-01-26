#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define LSOne(S) (S & -S)

ll hashfn(ll &x, ll &y) {
  return x*1e9+y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  pair<ll,ll> goal;
  cin >> goal.first >> goal.second;

  vector<ll> x(n), y(n);
  for (int i{0}; i < n; ++i) cin >> x[i] >> y[i];

  unordered_map<ll, int> curback;
  int curone{0};
  int half{n/2};
  vector<vector<int>> l(n, vector<int>(1<<21));
  for (int i{(1<<half)-1}; i >= 0; --i) {
    ll smx{0}, smy{0};
    int m{i}, bts{0};
    while (m) {
      smx += x[__builtin_ctz(m)];
      smy += y[__builtin_ctz(m)];
      m -= LSOne(m);
      ++bts;
    }
    ll hsd{hashfn(smx, smy)};
    if (curback.find(hsd) == curback.end()) {
      curback[hsd] = curone;
      ++curone;
    }
    ++l[bts][curback[hsd]];
  }

  vector<ll> ans(n);
  for (int i{(1<<(n-half))-1}; i >= 0; --i) {
    ll smx{0}, smy{0};
    int m{i}, bts{0};
    while (m) {
      smx += x[__builtin_ctz(m) + half];
      smy += y[__builtin_ctz(m) + half];
      m -= LSOne(m);
      ++bts;
    }
    smx = goal.first - smx;
    smy = goal.second - smy;
    ll hsh{hashfn(smx, smy)};
    if (curback.find(hsh) == curback.end()) {
      continue;
    } else {
      hsh = curback[hsh];
    }
    for (int j{bts - 1}; j - bts + 1 < n; ++j) {
      ans[j] += l[j - bts + 1][hsh];
    }
  }

  for (auto &ansp: ans) cout << ansp << "\n";

  return 0;
}
