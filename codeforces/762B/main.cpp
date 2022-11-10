#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll u, p, n, m;
  cin >> u >> p >> n >> m;

  priority_queue<ll, vector<ll>, greater<ll>> usb, ps2;
  ll cost;
  string type;
  for (ll i{0}; i < m; ++i) {
    cin >> cost >> type;
    if (type == "USB") {
      usb.push(cost);
    } else {
      ps2.push(cost);
    }
  }

  ll equipped{0}, totcost{0};
  for (ll i{0}; i < u && !usb.empty(); ++i) {
    ++equipped;
    totcost += usb.top();
    usb.pop();
  }
  for (ll i{0}; i < p && !ps2.empty(); ++i) {
    ++equipped;
    totcost += ps2.top();
    ps2.pop();
  }
  for (ll i{0}; i < n && (!ps2.empty() || !usb.empty()); ++i) {
    ll ans{LLONG_MAX};
    bool ps2orusb{0};
    if (!ps2.empty()) {
      ans = ps2.top();
    }
    if (!usb.empty()) {
      if (usb.top() < ans) {
        ps2orusb = 1;
        ans = usb.top();
      }
    }
    ++equipped;
    totcost += ans;
    if (ps2orusb) {
      usb.pop();
    } else {
      ps2.pop();
    }
  }

  cout << equipped << " " << totcost << "\n";

  return 0;
}
