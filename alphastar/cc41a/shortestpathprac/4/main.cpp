#include <bits/stdc++.h>

using namespace std;

typedef pair<int,pair<int,pair<int,int>>> piiii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> bred(n);
  for (int i{0}; i < n; ++i) {
    cin >> bred[i];
    --bred[i];
  }

  vector<vector<char>> g(k, vector<char>(k));
  char x;
  for (int i{0}; i < k; ++i) {
    for (int j{0}; j < k; ++j) {
      cin >> x;
      g[i][j] = x == '1';
    }
  }

  vector<vector<vector<int>>> dist(n, vector<vector<int>>(k, vector<int>(2, INT_MAX)));
  dist[0][bred[0]][1] = 0;
  priority_queue<piiii, vector<piiii>, greater<piiii>> pq;
  pq.push({0, {bred[0], {0, 1}}});
  while (pq.size()) {
    int d = pq.top().first;
    int breed = pq.top().second.first;
    int u = pq.top().second.second.first;
    int adjust = pq.top().second.second.second;
    pq.pop();
    if (d != dist[u][breed][adjust]) continue;
    if (u) {
      if (d + 1 < dist[u-1][breed][0]) {
        dist[u-1][breed][0] = d+1;
        pq.push({d+1, {breed, {u-1, 0}}});
      }
    }
    if (u < n-1) {
      if (d + 1 < dist[u+1][breed][0]) {
        dist[u+1][breed][0] = d+1;
        pq.push({d+1, {breed, {u+1, 0}}});
      }
    }
    if (g[breed][bred[u]] && dist[u][bred[u]][1] > d) {
      dist[u][bred[u]][1] = d;
      adjust = 1;
      breed = bred[u];
      if (u) {
        if (d + 1 < dist[u-1][breed][adjust]) {
          dist[u-1][breed][adjust] = d+1;
          pq.push({d+1, {breed, {u-1, 1}}});
        }
      }
      if (u < n-1) {
        if (d + 1 < dist[u+1][breed][adjust]) {
          dist[u+1][breed][adjust] = d+1;
          pq.push({d+1, {breed, {u+1, 1}}});
        }
      }
    }
  }

  cout << (dist[n-1][bred[n-1]][1]==INT_MAX?-1:dist[n-1][bred[n-1]][1]) << '\n';

  return 0;
}
