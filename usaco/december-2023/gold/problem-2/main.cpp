#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<ll> ind(n), outd(n);
  vector<vector<pii>> g(n);
  ll x, y, z;
  for (ll i{0}; i < m; ++i) {
    cin >> x >> y >> z;
    --x;--y;
    g[x].push_back({y, z});
    ++ind[x];
    ++outd[x];
  }

  priority_queue<pair<pii,int>, vector<pair<pii,int>>, greater<pair<pii,int>>> pq;
  for (ll i{0}; i < n; ++i) {
    if (ind[i] == 0) {
      pq.push({{0, 0}, i});
    }
  }

  vector<vector<pii>> gt(n);
  for (ll i{0}; i < n; ++i) {
    for (auto &v: g[i]) {
      gt[v.first].push_back({i, v.second});
    }
  }

  vector<ll> ans(n);
  ll pos{0};
  while (!pq.empty()) {
    ll u = pq.top().second; pq.pop();
    ans[u] = pos++;
    for (auto &v: gt[u]) {
      --ind[v.first];
      if (ind[v.first] > 0) continue;
      pq.push({{-v.second, pos}, v.first});
    }
  }

  // vector<ll> topo2(n);
  // vector<ll> toposort2;
  // toposort2.reserve(n);
  // pos = 0;
  // priority_queue<ll, vector<ll>, greater<ll>> pq2;
  // while (!pq.empty()) {
  //   ll u = pq.top().second; pq.pop();
  //   topo2[u] = pos++;
  //   toposort2.push_back(u);
  //   for (auto &v: g[u]) {
  //     --ind[v.first];
  //     if (ind[v.first] > 0) continue;
  //     pq.push(v.first);
  //   }
  // }
  // vector<ll> longest(n);
  // for (ll i{n-1}; i >= 0; --i) {

  // }

  // for (ll i{0}; i < n; ++i) {
  //   cout << ans[i] << ' ';
  // }
  // cout << '\n';

  vector<pii> ss(n);
  for (ll i{0}; i < n; ++i) {
    ss[i] = {ans[i], i};
  }
  sort(ss.begin(), ss.end());

  // cout << "ss\n";
  // for (ll i{0}; i < n; ++i) {
  //   cout << ss[i].first << ' ' << ss[i].second << '\n';
  // }
  // cout << "ss en\n" << '\n';

  vector<pair<pii, pii>> ansi(n);
  for (int i{0}; i < n; ++i) {
    ansi[i].first.first = -1;
  }
  for (ll i{0}; i < n; ++i) {
    if (ansi[ss[i].second].first.first == -1) ansi[ss[i].second] = {{0, 0}, {0, 0}};
    for (auto &v: gt[ss[i].second]) {
      // if (v.first == 3) {
      //   cout << ss[i].second << ' ' << v.second << ' ' << i << '\n';
      // }
      if (ansi[v.first].first.first == -1 || (1 + ansi[ss[i].second].first.first > ansi[v.first].first.first || (1 + ansi[ss[i].second].first.first == ansi[v.first].first.first && (ansi[v.first].second.first > v.second || (ansi[v.first].second.first == v.second && ans[ansi[v.first].second.second] < ans[ss[i].second]))))) {
        ansi[v.first].first.first = 1 + ansi[ss[i].second].first.first;
        ansi[v.first].first.second = v.second + ansi[ss[i].second].first.second;
        ansi[v.first].second = {v.second, ss[i].second};
      }
    }
  }

  for (auto anss: ansi) {
    cout << (anss.first.first==-1?0:anss.first.first) << ' ' << anss.first.second << '\n';
  }

  return 0;
}
