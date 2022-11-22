// Got to use DSU to make it fast enough for USACO guide graders, I'll get back when I learn that

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
pair<ll,ll> a[1000];
bool visited[1000];
ll dist[1000][1000];

inline ll comps(ll price) {
  vector<ll> g[n];
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j < n; ++j) {
      if (dist[i][j] <= price) {
        g[i].push_back(j);
      }
    }
  }
  for (ll i{0}; i < n; ++i) {
    visited[i] = 0;
  }
  ll components{0};
  for (ll i{0}; i < n; ++i) {
    if (visited[i]) continue;
    stack<ll> s;
    s.push(i);
    while (!s.empty()) {
      ll stop{s.top()};
      s.pop();
      visited[stop] = 1;
      for (auto &ne: g[stop]) {
        if (!visited[ne]) {
          s.push(ne);
        }
      }
    }
    ++components;
  }
  return components;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);

  cin >> n;
  for (ll i{0}; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j < n; ++j) {
      dist[i][j] = (pow(a[i].first - a[j].first, 2) + pow(a[i].second - a[j].second, 2));
    }
  }

  ll l{0};
  ll r{1250000000}, ans{-1};
  while (l <= r) {
    ll mid{(l+r)/2};
    if (comps(mid) == 1) {
      r = mid-1;
      ans = mid;
    } else {
      l = mid+1;
    }
  }

  cout << ans << "\n";

  return 0;
}
