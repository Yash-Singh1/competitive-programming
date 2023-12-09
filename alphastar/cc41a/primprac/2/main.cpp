#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  priority_queue<pair<ll,int>> pq;
  vector<bool> vis(n);
  vector<int> wval(n, -1);
  ll wtot{0};
  pq.push({0, 0});
  while (pq.size()) {
    ll w = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    wtot += w;
    for (int j{0}; j < n; ++j) {
      if (j == u) continue;
      ll wvalue = a[u] ^ a[j];
      if (!vis[j] && wvalue > wval[j]) {
        pq.push({wvalue, j});
        wval[j] = wvalue;
      }
    }
  }

  cout << wtot << '\n';

  return 0;
}
