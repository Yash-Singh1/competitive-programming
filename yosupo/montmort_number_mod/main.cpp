#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;
  atcoder::modint::set_mod(m);
  atcoder::modint ans{1};

  for (ll i{1}; i <= n; ++i) {
    ans = (ans * i) + (i & 1 ? -1 : 1);
    cout << ans.val() << " ";
  }

  cout << "\n";

  return 0;
}
