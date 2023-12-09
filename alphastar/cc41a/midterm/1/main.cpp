#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, n;
  cin >> a >> b >> n;

  vector<vector<int>> routes(n);
  vector<ll> croute(n);
  int p, x;
  for (int i{0}; i < n; ++i) {
    cin >> croute[i] >> p;
    while (p--) {
      cin >> x;
      routes[i].push_back(x);
    }
  }

  vector<vector<int>> post(n, vector<int>(1001, -1));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < (int)routes[i].size()-1; ++j) {
      post[i][routes[i][j]] = routes[i][j+1];
    }
  }

  // for (int i{0}; i < n; ++i) {
  //   for (int j{0}; j < 6; ++j) {
  //     cout << post[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  vector<vector<pll>> dist(n+1, vector<pll>(1001, {LLONG_MAX, LLONG_MAX}));

  // {{cost, alt_cost}, {route, city}}
  priority_queue<pair<pll,pii>, vector<pair<pll,pii>>, greater<pair<pll,pii>>> pq;
  pq.push({{0, 0}, {n, a}});
  dist[n][a] = {0, 0};
  while (pq.size()) {
    ll dc = pq.top().first.first;
    ll dt = pq.top().first.second;
    int r = pq.top().second.first;
    int u = pq.top().second.second;
    pq.pop();
    if (dist[r][u] != pll{dc, dt}) continue;
    if (r < n && post[r][u] >= 0) {
      if (dc < dist[r][post[r][u]].first || (dc == dist[r][post[r][u]].first && dt+1 < dist[r][post[r][u]].second)) {
        dist[r][post[r][u]] = {dc, dt+1};
        pq.push({dist[r][post[r][u]], {r, post[r][u]}});
      }
    }
    for (int i{0}; i < n; ++i) {
      if (r != i && post[i][u] >= 0) {
        // cout << (dc + croute[i]) << ' ' << dist[i][post[i][u]].first << '\n';
        if (dc + croute[i] < dist[i][post[i][u]].first || (dc + croute[i] == dist[i][post[i][u]].first && dt + 1 < dist[i][post[i][u]].second)) {
          dist[i][post[i][u]] = {dc + croute[i], dt + 1};
          pq.push({dist[i][post[i][u]], {i, post[i][u]}});
        }
      }
    }
  }

  ll mn{LLONG_MAX}, mn2{LLONG_MAX};
  for (int i{0}; i <= n; ++i) {
    if (dist[i][b].first < mn) {
      mn = dist[i][b].first;
      mn2 = dist[i][b].second;
    } else if (dist[i][b].first == mn && dist[i][b].second < mn2) {
      mn2 = dist[i][b].second;
    }
  }

  if (mn == LLONG_MAX) mn = -1;
  if (mn2 == LLONG_MAX) mn2 = -1;

  cout << mn << ' ' << mn2 << '\n';

  // cout << "-----\n";
  // for (int i{0}; i <= n; ++i) {
  //   for (int j{0}; j < 6; ++j) {
  //     cout << (dist[i][j].first==LLONG_MAX?-1:dist[i][j].first) << ' ';
  //   }
  //   cout << '\n';
  // }
  // cout << '\n';

  return 0;
}
