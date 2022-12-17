// For each component the answer is the sum of all the edges minus the minimum edge that contributes to a cycle 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
vector<pair<ll,ll>> g(100000);
vector<ll> mcyclic(100000);
vector<ll> smcyclic(100000);
vector<ll> cyclid(100001);
ll cyclei{0};
bool cycling{0};
vector<bool> visited(100000);

void dfs(ll i) {
  if (cyclid[i] != -1) {
    return;
  }
  if (visited[i]) {
    cycling = 1;
    cyclid[i] = cyclei;
    mcyclic[cyclei] = min(mcyclic[cyclei], g[i].second);
    smcyclic[cyclei] += g[i].second;
    return;
  }
  visited[i] = 1;
  dfs(g[i].first);
  if (cycling) {
    mcyclic[cyclid[g[i].first]] = min(mcyclic[cyclid[g[i].first]], g[i].second);
  }
  if (cyclid[i] != -1) {
    cycling = 0;
    ++cyclei;
  } else {
    smcyclic[cyclid[g[i].first]] += g[i].second;
  }
  cyclid[i] = cyclid[g[i].first];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (ll i{0}; i < n; ++i) {
    cin >> g[i].first >> g[i].second;
    --g[i].first;
    mcyclic[i] = LLONG_MAX;
    cyclid[i] = -1;
    smcyclic[i] = 0;
    visited[i] = 0;
  }

  for (int i{0}; i < n; ++i) dfs(i);

  ll ans{0};
  for (ll i{0}; i < cyclei; ++i) {
    ans += smcyclic[i] - mcyclic[i];
  }

  cout << ans << "\n";

  return 0;
}
