#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, c;
  cin >> n >> c;

  vector<pii> p(n);
  for (int i{0}; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
  }

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, 0});
  int wtot{0};
  vector<pii> e;
  vector<bool> vis(n, 0);
  int vc{0};
  e.reserve(n-1);
  while (pq.size()) {
    int w = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    ++vc;
    wtot += w;
    for (int j{0}; j < n; ++j) {
      int ww{(int)pow(p[u].first - p[j].first, 2) + (int)pow(p[u].second - p[j].second, 2)};
      if (!vis[j] && j != u && ww >= c) {
        pq.push({ww, j});
      }
    }
  }

  if (vc < n) {
    cout << -1 << '\n';
  } else {
    cout << wtot << '\n';
  }

  return 0;
}
