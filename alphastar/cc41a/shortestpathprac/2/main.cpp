#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m, k;
  cin >> n >> m >> k;

  vector<vector<pii>> g(n);
  ll x, y, z;
  for (ll i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x; --y;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }

  vector<pii> spec(k);
  for (ll i{0}; i < k; ++i) {
    cin >> spec[i].first >> spec[i].second;
    --spec[i].first;
  }

  vector<ll> dist1(n, LLONG_MAX);
  dist1[n-1] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, n-1});
  while (pq.size()) {
    ll d = pq.top().first;
    ll u = pq.top().second;
    pq.pop();
    if (d != dist1[u]) continue;
    for (auto &v: g[u]) {
      if (d + v.second < dist1[v.first]) {
        dist1[v.first] = d + v.second;
        pq.push({dist1[v.first], v.first});
      }
    }
  }

  vector<ll> dist2(n, LLONG_MAX);
  for (ll i{0}; i < k; ++i) {
    dist2[spec[i].first] = dist1[spec[i].first] - spec[i].second;
    pq.push({dist2[spec[i].first], spec[i].first});
  }

  while (pq.size()) {
    ll d = pq.top().first;
    ll u = pq.top().second;
    pq.pop();
    if (d != dist2[u]) continue;
    for (auto &v: g[u]) {
      if (d + v.second < dist2[v.first]) {
        dist2[v.first] = d + v.second;
        pq.push({dist2[v.first], v.first});
      }
    }
  }

  for (ll i{0}; i < n-1; ++i) {
    if (dist2[i] <= dist1[i]) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }

  return 0;
}
