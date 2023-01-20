#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<pair<int,pair<int,int>>> adj(m);
  for (int i{0}; i < m; ++i) {
    cin >> adj[i].first >> adj[i].second.first >> adj[i].second.second;
    // --adj[i].first; --adj[i].second.first;
  }

  vector<int> dist(n, 10000);
  dist[0] = 0;

  for (int i{1}; i < n; ++i) {
    for (auto &edge: adj) {
      if (dist[edge.first] != 10000 && dist[edge.first] + edge.second.second < dist[edge.second.first]) {
        dist[edge.second.first] = dist[edge.first] + edge.second.second;
      }
    }
  }

  for (int i{1}; i < n; ++i) {
    for (auto &edge: adj) {
      if (dist[edge.first] != 10000 && dist[edge.first] + edge.second.second < dist[edge.second.first]) {
        dist[edge.second.first] = -10000;
      }
    }
  }

  for (int i{0}; i < n; ++i) {
    if (dist[i] == -10000) {
      cout << "-inf ";
    } else {
      cout << dist[i] << " ";
    }
  }
  cout << "\n";

  return 0;
}
