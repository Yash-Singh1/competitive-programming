#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  ll sm{0};
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    sm += a[i];
  }

  ll cur{0};
  ll ans{0};
  for (int i{0}; i < n; ++i) {
    ans = max(ans, cur * sm);
    sm -= a[i];
    cur += a[i] * a[i];
  }

  cout << ans << '\n';

  return 0;
}
