#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll v[200000];
vector<ll> g[200000];
ll avg{0};
// vector<pair<ll,pair<ll,ll>>> ans;
vector<pair<ll,pair<ll,ll>>> ic, dc;

ll dfs(ll i, ll p) {
  ll tot{0};
  for (auto &ne: g[i]) {
    if (ne != p) {
      ll c{dfs(ne, i)};
      if (c > 0) {
        dc.push_back({c, {ne, i}});
      } else if (c < 0) {
        ic.push_back({c, {i, ne}});
      }
      tot += c;
    }
  }
  // for (auto &de: dc) {
  //   ans.push_back({de.second, {de.first, i}});
  // }
  // for (auto &ie: ic) {
  //   ans.push_back({ie.second, {i, ie.first}});
  // }
  return tot + avg - v[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  for (ll i{0}; i < n; ++i) {
    cin >> v[i];
    avg += v[i];
  }
  avg /= n;

  ll x, y;
  for (ll i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(0, -1);

  cout << (ll)ic.size() + (ll)dc.size() << "\n";
  for (auto &ani: ic) {
    cout << ani.second.second + 1LL << " " << ani.second.first + 1LL << " " << abs(ani.first) << "\n";
  }
  for (ll i{(ll)dc.size() - 1LL}; i >= 0; --i) {
    cout << dc[i].second.second + 1LL << " " << dc[i].second.first + 1LL << " " << abs(dc[i].first) << "\n";
  }

  return 0;
}
