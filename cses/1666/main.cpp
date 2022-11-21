#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<ll> g[n];
  ll x, y;
  for (ll i{0}; i < m; ++i) {
    cin >> x >> y;
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  bool visited[n];
  for (ll i{0}; i < n; ++i) {
    visited[i] = 0;
  }

  ll comps{0};
  ll head[n];
  for (ll i{0}; i < n; ++i) {
    if (!visited[i]) {
      head[comps]=i;
      ++comps;
      stack<ll> s;
      s.push(i);
      while (!s.empty()) {
        ll stop{s.top()};
        s.pop();
        visited[stop]=1;
        for (auto &ne: g[stop]) {
          if (!visited[ne]) {
            s.push(ne);
          }
        }
      }
    }
  }

  cout << comps-1 << "\n";
  for (ll i{0}; i < comps-1; ++i) {
    cout << head[i]+1 << " " << head[i+1]+1 << "\n";
  }

  return 0;
}
