#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const ll MOD = 2019201997;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  // prim to n-k edges, can calc mst and sub k-1 longest edges
  priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
  vector<bool> vis(n);
  vector<ll> wval(n-1, LLONG_MAX);
  pq.push({0, 0});
  set<ll> ws;
  while (pq.size()) {
    ll w = pq.top().first;
    int u = pq.top().second;
    // cout << w << " " << u << '\n';
    pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    // if (u) wval[u-1] = w;
    for (int j{1}; j < n; ++j) {
      if (j == u) continue;
      ll wvalue = ((2019201913LL * (min(u,j)+1))%MOD + (2019201949LL * (max(j,u)+1))%MOD)%MOD;
      // if (j == n-1) {
      //   cout << "hitithere " << u << ' ' << vis[j] << ' ' << wvalue << '\n';
      // }
      // if (u == n-1) {
      //   cout << "hitoverhere " << j << ' ' << vis[j] << ' ' << wvalue << '\n';
      // }
      if (!vis[j] && wvalue < wval[j-1]) {
        pq.push({wvalue, j});
        if (j) wval[j-1] = wvalue;
      }
    }
  }

  sort(wval.begin(), wval.end());

  cout << wval[n-k] << '\n';

  return 0;
}
