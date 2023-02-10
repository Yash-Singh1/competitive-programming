#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

bool sortY(pair<pii,int> &a, pair<pii,int> &b) {
  if (a.first.second == b.first.second) return a.first.first < b.first.first;
  return a.first.second < b.first.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lasers.in", "r", stdin);
  freopen("lasers.out", "w", stdout);

  int n;
  cin >> n;

  vector<pii> p(n+2);
  cin >> p[0].first >> p[0].second >> p[n+1].first >> p[n+1].second;
  for (int i{1}; i <= n; ++i) {
    cin >> p[i].first >> p[i].second;
  }

  map<pii,int> next;
  vector<pair<pii,int>> s(n+2);
  for (int i{0}; i < n+2; ++i) {
    s[i] = {p[i], i};
  }
  sort(s.begin(), s.end());
  // 0: north, 1: east, 2: south, 3: west
  for (int i{0}; i <= n+1; ++i) {
    if (i) {
      if (s[i-1].first.first == s[i].first.first) {
        next[{s[i].second, 2}] = s[i-1].second;
      }
    }
    if (i <= n) {
      if (s[i+1].first.first == s[i].first.first) {
        next[{s[i].second, 0}] = s[i+1].second;
      }
    }
  }
  sort(s.begin(), s.end(), sortY);
  for (int i{0}; i <= n+1; ++i) {
    if (i) {
      if (s[i-1].first.second == s[i].first.second) {
        next[{s[i].second, 3}] = s[i-1].second;
      }
    }
    if (i <= n) {
      if (s[i+1].first.second == s[i].first.second) {
        next[{s[i].second, 1}] = s[i+1].second;
      }
    }
  }

  // Precompute graph with edges
  // Consider direction and point two props of nodes
  // Pass through doesn't count as mirror, but still iterate
  // BFS for shortest path

  queue<pii> q;
  map<pii,int> dist;
  q.push({0, 1}); q.push({0, 2});
  q.push({0, 0}); q.push({0, 4});
  int opp[4]; opp[0] = 2; opp[2] = 0; opp[1] = 3; opp[3] = 1;

  while (q.size()) {
    int u = q.front().first;
    int d = q.front().second;
    q.pop();
    if (next.find({u, d}) != next.end()) {
      // Evaluate each direction except for opp.
      int nx = next[{u,d}];
      for (int j{0}; j < 4; ++j) {
        if (j == opp[d]) continue;
        int diff{1};
        if (j == d) diff = 0;
        if (dist.find({nx, j}) == dist.end() || dist[{u, d}] + diff < dist[{nx, j}]) {
          dist[{nx,j}] = dist[{u,d}]+diff;
          q.push({nx, j});
        }
      }
    }
  }

  int ans{INT_MAX};
  for (int i{0}; i < 4; ++i) {
    if (dist.find({n+1,i}) != dist.end()) ans = min(ans, dist[{n+1, i}]);
  }

  cout << (ans==INT_MAX?-1:ans) << "\n";

  return 0;
}
