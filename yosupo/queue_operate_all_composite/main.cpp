#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

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

  int q;
  cin >> q;

  ll t, a, b;
  deque<pll> dq;
  ll curm{1}, curb{0};
  while (q--) {
    cin >> t;
    if (t == 0) {
      cin >> a >> b;
      dq.push_back({a, b});
      curb = (mulmod(curb, a, MOD) + b) % MOD;
      curm = mulmod(curm, a, MOD);
    } else if (t == 1) {
      curm = mulmod(curm, binpow(dq.front().first, MOD - 2, MOD), MOD);
      curb = (((curb - mulmod(curm, dq.front().second, MOD)) % MOD) + MOD) % MOD;
      dq.pop_front();
    } else {
      cin >> a;
      cout << (mulmod(a, curm, MOD) + curb) % MOD << "\n";
    }
  }

  return 0;
}
