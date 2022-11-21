#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<ll> g[n];
  ll x, y;
  for (ll i{0}; i < n-1; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  stack<ll>s;
  s.push(0);
  bool visited[n];
  ll color[n];
  for (ll i{0}; i < n; ++i) {
    visited[i] = 0;
    color[i] = -1;
  }
  color[0] = 0;
  while (!s.empty()) {
    ll stop{s.top()};
    s.pop();
    visited[stop] = 1;
    for (auto &ne: g[stop]) {
      if (color[ne] == -1) {
        color[ne] = 1 - color[stop];
      }
      if (!visited[ne]) {
        s.push(ne);
      }
    }
  }

  ll uncolorc{0}, colorc{0};
  for (ll i{0}; i < n; ++i) {
    if (color[i] == 1) {
      ++colorc;
    } else {
      ++uncolorc;
    }
  }

  cout << (uncolorc * colorc) - n + 1 << "\n";

  return 0;
}
