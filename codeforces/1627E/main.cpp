#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Ladder {
  ll x1, x2, y1, y2, h;
};

typedef pair<ll,ll> pll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;

  while (t--) {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> f(n);
    for (ll i{0}; i < n; ++i) {
      cin >> f[i];
    }

    vector<pll> coords;
    vector<vector<Ladder>> ladders(n);
    Ladder ini;
    for (ll i{0}; i < k; ++i) {
      cin >> ini.x1 >> ini.y1 >> ini.x2 >> ini.y2 >> ini.h;
      --ini.x1; --ini.y1; --ini.x2; --ini.y2;
      // la[{ini.x1, ini.y1}] = {{ini.x2, ini.y2}, ini.h};
      ladders[ini.x1].push_back(ini);
      coords.push_back({ini.x1, ini.y1});
      coords.push_back({ini.x2, ini.y2});
    }

    coords.push_back({0, 0});
    coords.push_back({n-1, m-1});

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    // cout << "------\n";
    // cout <<t << "\n";
    // for (auto &coord: coords) {
    //   cout << coord.first << ' ' << coord.second << '\n';
    // }
    // cout << "-------\n";

    map<pll,ll> rev;
    for (ll i{0}; i < coords.size(); ++i) {
      rev[coords[i]] = i;
    }

    // dijkstra won't run around neg weights
    // however we could mallain a DP for each room
    // we can run a mini-BFS in each floor to push all of the sideways costs

    // vector<vector<ll>> dp(n, vector<ll>(m, LLONG_MAX));
    // dp[0][0] = 0;

    // however we shouldn't be visiting all nodes, only ladder starts or end polls
    // this can be handled using coordinate compression, giving us an upper bound of 2*k+2 polls

    // running a mini-BFS (all edges are pos) on each floor is reasonable now with two pollers, because the summation will be linear at most
    // after that we can iterate through and push up all ladder start polls

    vector<ll> dp(coords.size(), LLONG_MAX);
    dp[0] = 0;
    ll l{0}, r{0};
    while (l < coords.size()) {
      while (r < coords.size() && coords[r].first == coords[l].first) ++r;
      // we have to run dijkstra because we can have quadratic time otherwise
      priority_queue<pll, vector<pll>, greater<pll>> q;
      for (ll i{l}; i < r; ++i) {
        if (dp[i] != LLONG_MAX) {
          // cout << t << ' ' << i << ' ' << coords[i].first << ' ' << coords[i].second << "\n";
          q.push({dp[i], i});
        }
      }
      // cout << l << " " << r << " " << coords[l].first << '\n';
      while (q.size()) {
        ll u = q.top().second;
        ll d = q.top().first;

        // cout << "info " << u << ' ' << coords[u].first << ' ' << coords[u].second << " " << d << '\n';
        q.pop();
        // if (d != dp[u]) continue;
        ll prop;

        // u-1
        if (u-1 >= l && (prop = dp[u] + abs(coords[u].second-coords[u-1].second) * f[coords[u].first]) < dp[u-1]) {
          assert(coords[u].first == coords[u-1].first);
          dp[u-1] = prop;
          q.push({prop, u-1});
        }

        // u+1
        if (u+1 < r && (prop = dp[u] + abs(coords[u].second-coords[u+1].second) * f[coords[u].first]) < dp[u+1]) {
          assert(coords[u].first == coords[u+1].first);
          dp[u+1] = prop;
          q.push({prop, u+1});
        }
      }

      for (auto &ladder: ladders[coords[l].first]) {
        if (dp[rev[{ladder.x1, ladder.y1}]] == LLONG_MAX) continue;
        ll nx{rev[{ladder.x2, ladder.y2}]};
        dp[nx] = min(dp[nx], dp[rev[{ladder.x1, ladder.y1}]] - ladder.h);
      }
      l = r;
    }

    if (dp[coords.size()-1] == LLONG_MAX) {
      cout << "NO ESCAPE\n";
    } else {
      cout << dp[coords.size()-1] << '\n';
    }
  }

  return 0;
}
