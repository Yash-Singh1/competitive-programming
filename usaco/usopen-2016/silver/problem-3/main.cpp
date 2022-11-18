#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("closing.in", "r", stdin);
  freopen("closing.out", "w", stdout);

  ll n, m;
  cin >> n >> m;

  ll x, y;
  vector<ll> g[n];
  for (ll i{0}; i < m; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  ll rm;
  ll tot{n};
  bool blocked[n];
  for (ll i{0}; i < n;++i) {
    blocked[i]=0;
  }
  bool visited[n];
  ll totg{0};
  for (ll j{0}; j < n; ++j) {
    for (ll i{0}; i < n; ++i) {
      visited[i]=0;
    }
    stack<ll> s;
    for (ll i{0}; i < n; ++i) {
      if (!blocked[i]) {
        s.push(i);
        break;
      }
    }
    while (!s.empty()) {
      ll tp{s.top()};
      s.pop();
      visited[tp]=1;
      for (ll &neighbor: g[tp]) {
        if (!visited[neighbor] && !blocked[neighbor]) {
          s.push(neighbor);
        }
      }
    }

    totg=0;
    for (ll i{0}; i < n; ++i) {
      if (visited[i]) ++totg;
    }
    if (totg == tot) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
    cin >> rm;
    --rm;
    blocked[rm]=1;
    --tot;
  }

  return 0;
}
