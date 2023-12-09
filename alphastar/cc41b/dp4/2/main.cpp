#include <bits/stdc++.h>

using namespace std;

typedef pair<pair<int,int>,int> Interval;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, r;
  cin >> n >> m >> r;
  vector<Interval> a(m);
  for (int i{0}; i < m; ++i) {
    cin >> a[i].first.first >> a[i].first.second >> a[i].second;
  }
  sort(a.begin(), a.end());

  vector<int> dp(n+1);
  for (int i{0}; i < n; ++i) {
    Interval nx = *lower_bound(a.begin(), a.end(), Interval{{i, -1}, -1});
    dp[min(n, nx.first.second+r)] = max(dp[min(n, nx.first.second+r)], dp[i] + nx.second);
    dp[i+1] = max(dp[i], dp[i+1]);
  }

  cout << dp[n] << '\n';

  return 0;
}
