#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
ll n, t;

pll change(pll u, ll movement) {
  for (ll i{0}; i < 3; ++i) {
    if (movement & (1<<(2*i))) {
      if (movement & (1<<(2*i+1))) {
        --u.first;
      } else {
        --u.second;
      }
    } else {
      if (movement & (1<<(2*i+1))) {
        ++u.first;
      } else {
        ++u.second;
      }
    }
    if (i != 2 && u.first == n - 1 && u.second == n - 1) {
      return {LLONG_MIN, i + 1};
    }
  }
  return u;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("visitfj.in", "r", stdin);
  freopen("visitfj.out", "w", stdout);

  cin >> n >> t;

  vector<vector<ll>> time(n, vector<ll>(n));
  for (ll i{0}; i < n; ++i) {
    for (ll j{0}; j < n; ++j) {
      cin >> time[i][j];
    }
  }

  vector<vector<ll>> dist(n, vector<ll>(n, 1e15));
  dist[0][0] = 0;
  priority_queue<pair<ll,pll>, vector<pair<ll,pll>>, greater<pair<ll,pll>>> q;
  q.push({0, {0, 0}});
  while (!q.empty()) {
    pll u = q.top().second;
    ll d = q.top().first;
    q.pop();
    if (d != dist[u.first][u.second]) continue;
    // reach goal without actually having three steps
    for (ll i{0}; i < (1<<8); ++i) {
      pll newm{change(u, i)};
      if (newm.first == LLONG_MIN) {
        dist[n - 1][n - 1] = min(dist[n - 1][n - 1], d + (newm.second * t));
      } else {
        if (newm.first < 0 || newm.first >= n || newm.second < 0 || newm.second >= n) continue;
        if (d + time[newm.first][newm.second] + 3*t < dist[newm.first][newm.second]) {
          dist[newm.first][newm.second] = d + time[newm.first][newm.second] + 3*t;
          q.push({dist[newm.first][newm.second], newm});
        }
      }
    }
  }

  cout << dist[n - 1][n - 1] << "\n";

  return 0;
}
