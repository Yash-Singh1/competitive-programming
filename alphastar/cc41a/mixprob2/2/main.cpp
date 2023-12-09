#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> order(m);
  ll x;
  for (ll i{0}; i < m; ++i) {
    cin >> x;
    order[i].resize(x);
    for (ll j{0}; j < x; ++j) {
      cin >> order[i][j];
      --order[i][j];
    }
  }

  vector<ll> in(n);
  vector<ll> orderans(n);
  ll l{0}, r{m-1}, ans{0};
  while (l <= r) {
    ll mid{(l+r)/2};
    vector<ll> ordert(n);
    ll t{0};
    for (ll i{0}; i < n; ++i) {
      in[i] = 0;
    }
    vector<vector<ll>> g(n);
    for (ll i{0}; i < mid; ++i) {
      // cout << i << " ";
      for (ll j{1}; j < (ll)order[i].size(); ++j) {
        ++in[order[i][j]];
        g[order[i][j-1]].push_back(order[i][j]);
      }
    }
    // cout << "ININ ";
    // for (ll i{0}; i < n; ++i) {
    //   cout << in[i] << ' ';
    // }
    // cout << '\n';
    for (ll i{0}; i < n; ++i) {
      sort(g[i].begin(), g[i].end(), greater<ll>());
    }
    priority_queue<ll, vector<ll>, greater<ll>> s;
    for (ll i{n-1}; i >= 0; --i) {
      if (!in[i]) s.push(i);
    }
    vector<ll> v(n);
    bool fail{0};
    while (s.size()) {
      ll u = s.top();
      s.pop();
      if (v[u]) {
        fail = 1;
        break;
      }
      ordert[t++] = u+1;
      v[u] = 1;
      for (auto &ne: g[u]) {
        --in[ne];
        if (!in[ne]) s.push(ne);
        assert(in[ne] >= 0);
      }
    }
    if (t != n) {
      r = mid-1;
    } else {
      l = mid+1;
      ans = mid;
      // cout << "MID" << mid << " ";
      // for (auto &ordere: ordert) {
      //   cout << ordere << ' ';
      // }
      // cout << '\n';
      orderans = ordert;
    }
  }

  for (auto &an: orderans) {
    cout << an << ' ';
  }
  cout << '\n';

  return 0;
}
