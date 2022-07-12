#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
const int N = 100005;
const int mx = INT_MAX - 10;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int s;
  int f;
  cin >> n >> s >> f;
  vector<pair<int, int>> graph[n + 2];
  for (int i{0}; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    graph[x].push_back({z, y});
    graph[y].push_back({z, x});
  }
  for (int i{0}; i < 5; ++i) {
    for (auto p: graph[i]) {
      cout << p.ff << "/" << p.ss << " ";
    }
    cout << endl;
  }
  priority_queue<pair<int, int>> pq;
  vector<bool> vis(n, 0);
  vector<int> dis(n, mx);
  dis[s] = 0;
  pq.push({ 0, s });
  while (!pq.empty()) {
    auto t{pq.top()};
    if (vis[t.ss] == 1) {
      pq.pop();
      continue;
    }
    int w {t.ff * -1};
    vis[t.ss] = 1;
    pq.pop();
    for (auto ne: graph[t.ss]) {
      if (dis[ne.ss] > w + ne.ff) {
        if (vis[ne.ss] == 1) {
          continue;
        }
        dis[ne.ss] = w + ne.ff;
        pq.push({ -1 * dis[ne.ss], ne.ss });
      }
    }
  }
  for (int i{0}; i < n; ++i) {
    cout << dis[i] << " ";
  }
}
