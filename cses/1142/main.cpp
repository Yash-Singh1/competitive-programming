#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; 
  cin >> n;
  
  vector<ll> a(n);
  for (ll i{0}; i < n; ++i) cin >> a[i];

  stack<pair<ll,ll>> s;
  vector<ll> mrec(n);
  for (ll i{0}; i < n; ++i) {
    while (s.size() && s.top().first >= a[i]) {
      s.pop();
    }
    if (s.size()) {
      mrec[i] = a[i] * (i - s.top().second);
    } else {
      mrec[i] = a[i] * (i + 1);
    }
    s.push({a[i], i});
  }
  stack<pair<ll,ll>> b;
  ll ans{0};
  for (ll i{n - 1}; i >= 0; --i) {
    while (b.size() && b.top().first >= a[i]) {
      b.pop();
    }
    if (b.size()) {
      mrec[i] += a[i] * (b.top().second - i - 1);
    } else {
      mrec[i] += a[i] * (n - i - 1);
    }
    ans = max(mrec[i], ans);
    b.push({a[i], i});
  }

  cout << ans << "\n";

  return 0;
}
