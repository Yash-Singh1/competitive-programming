#include <bits/stdc++.h>

using namespace std;

typedef int ll;

struct Edge {
  ll f, s, w;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll f, n, m, w;
  cin >> f;
  while (f--) {
    cin >> n >> m >> w;

    vector<Edge> edge;
    edge.reserve(2*m+w);
    ll x, y, z;
    for (ll i{0}; i < m+w; ++i) {
      cin >> x >> y >> z;
      if (i >= m) {
        edge.push_back({x, y, -z});
      } else {
        edge.push_back({x, y, z});
        edge.push_back({y, x, z});
      }
    }

    vector<ll> dist(n, INT_MAX);
    dist[0] = 0;
    for (ll i{0}; i < n; ++i) {
      for (auto &e: edge) {
        if (dist[e.f] == INT_MAX) {
          continue;
        }
        if (dist[e.f] + e.w < dist[e.s]) {
          dist[e.s] = dist[e.f] + e.w;
        }
      }
    }

    bool yes{0};
    for (auto &e: edge) {
      if (dist[e.f] == INT_MAX) {
        continue;
      }
      if (dist[e.f] + e.w < dist[e.s]) {
        yes = 1;
      }
    }

    if (yes || dist[0] < 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
