#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

ll mulmod(ll a, ll b, ll m) {
  return (ll)(((__int128)a * (__int128)b) % m);
}

ll binpow(ll a, ll b, ll m) {
  if (b == 0) {
    return 1;
  } else if (a == 0) {
    return 0;
  }
  ll curp{a};
  ll pow{0};
  ll ans{1};
  while (b) {
    if (b & (1<<pow)) {
      b &= b - 1;
      ans = mulmod(ans, curp, m);
    }
    ++pow;
    curp = mulmod(curp, curp, m);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  ll ans{0};
  int k, x;
  vector<vector<int>> list(n);
  unordered_map<int,int> c;
  for (int i{0}; i < n; ++i) {
    cin >> k;
    for (int j{0}; j < k; ++j) {
      cin >> x;
      list[i].push_back(x);
      ++c[x];
    }
  }

  for (int i{0}; i < n; ++i) {
    ll dem{binpow((ll)list[i].size() * n * n, MOD - 2, MOD)};
    for (auto &xi: list[i]) {
      ans += mulmod(dem, c[xi], MOD);
      ans %= MOD;
    }
  }

  cout << ans << "\n";

  return 0;
}
