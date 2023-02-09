#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("timeline.in", "r", stdin);
  freopen("timeline.out", "w", stdout);

  int n, m, c;
  cin >> n >> m >> c;

  vector<int> ss(n);
  for (int i{0}; i < n; ++i) cin >> ss[i];

  vector<int> in(n); int a, b, z;
  vector<vector<pii>> g(n);
  for (int i{0}; i < c; ++i) {
    cin >> a >> b >> z; --a; --b;
    g[a].push_back({b, z});
    ++in[b];
  }

  stack<int> s;
  vector<int> dp(n, INT_MAX);
  for (int i{0}; i < n; ++i) {
    dp[i] = ss[i];
    if (!in[i]) {
      s.push(i);
    }
  }
  while (s.size()) {
    int u = s.top();
    s.pop();
    for (auto &v: g[u]) {
      dp[v.first] = max(ss[v.first], max(dp[v.first], dp[u] + v.second));
      --in[v.first];
      if (!in[v.first]) s.push(v.first);
    }
  }

  for (int i{0}; i < n; ++i) {
    if (dp[i] == INT_MAX){
      cout << ss[i] << "\n";
    } else {
      cout << dp[i] << "\n";
    }
  }

  return 0;
}
