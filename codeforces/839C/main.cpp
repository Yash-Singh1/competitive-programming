// avg out path distances uptill leaf nodes

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

typedef long long ll;

typedef pair<ll,ll> pll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<ll> g[n];
  ll x, y;
  for (ll i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  // for (ll i{0}; i < n; ++i) {
  //   cout << i << " ";
  //   for (auto &ne: g[i]) {
  //     cout << ne << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  stack<pair<pll,long double>> s;
  long double sm{0};
  s.push({{0, 0}, 1});
  bool visited[n];
  for (ll i{0}; i < n; ++i) {
    visited[i] = 0;
  }
  while (!s.empty()) {
    pair<pll,long double> stop{s.top()};
    s.pop();
    bool contrib{0};
    visited[stop.first.first] = 1;
    for (auto &ne: g[stop.first.first]) {
      // cout << "CHECK" << " " << stop.first.first << " " << stop.first.second << " " << ne << "\n";
      if (!visited[ne]) {
        s.push({{ne, stop.first.second + 1}, stop.second * (1.0L/(g[stop.first.first].size() - (stop.first.first == 0 ? 0 : 1)))});
        contrib = 1;
      }
    }
    if (!contrib) {
      // cout << stop.first << " " << stop.second << " " << powl(2.0L, -stop.second) << "\n";
      // cout << stop.first.second << " " << stop.second << "\n";
      sm += stop.first.second * stop.second;
    }
  }

  // cout << "\n";
  cout << fixed << setprecision(12) << sm << "\n";

  return 0;
}
