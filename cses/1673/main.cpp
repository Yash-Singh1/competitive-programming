#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<pair<ll,pair<ll,ll>>> adj(m);
  for (ll i{0}; i < m; ++i) {
    cin >> adj[i].first >> adj[i].second.first >> adj[i].second.second;
    --adj[i].first; --adj[i].second.first;
    adj[i].second.second *= -1;
  }

  vector<ll> dist(n, (ll)6e12);
  dist[0] = 0;
  for (ll i{1}; i < n; ++i) {
    for (auto &edge: adj) {
      if (dist[edge.first] != (ll)6e12 && dist[edge.first] + edge.second.second < dist[edge.second.first]) {
        dist[edge.second.first] = dist[edge.first] + edge.second.second;
      }
    }
  }

  for (int i{1}; i < n; ++i) {
    for (auto &edge: adj) {
      if (dist[edge.first] != (ll)6e12 && dist[edge.first] + edge.second.second < dist[edge.second.first]) {
        dist[edge.second.first] = -(ll)6e12;
      }
    }
  }

  if (dist[n - 1] == -(ll)6e12) {
    cout << "-1\n";
  } else {
    cout << -dist[n-1] << "\n";
  }

  return 0;
}
