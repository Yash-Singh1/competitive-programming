#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll x, n;
  cin >> x >> n;

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll y;
  for (ll i{0}; i < n; ++i) {
    cin >> y;
    pq.push(y);
  }

  ll ans{0};
  for (ll i{1}; i < n; ++i) {
    ll a{pq.top()};
    pq.pop();
    ll b{pq.top()};
    pq.pop();
    ans += a+ b;
    pq.push(a+b);
  }

  cout << ans << "\n";

  return 0;
}
