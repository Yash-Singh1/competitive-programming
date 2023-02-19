#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define LSOne(S) ((S) & -(S))

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> p(n), notes(m);
  for (int i{0}; i < n; ++i) cin >> p[i];
  for (int i{0}; i < m; ++i) cin >> notes[i];

  vector<deque<pii>> dp(n+1);
  vector<bool> vis(1<<m);
  // We know that each bitmask can visit a corresponding prefix only once so we use deques and iterate
  dp[0].push_back({(1<<m)-1, 0});
  for (int i{0}; i < n; ++i) {
    while (dp[i].size()) {
      if (dp[i].front().second == p[i]) {
        dp[i + 1].push_back({dp[i].front().first, 0});
        dp[i].pop_front();
        continue;
      }
      int b{dp[i].front().first};
      while (b) {
        if (!vis[dp[i].front().first^LSOne(b)] && dp[i].front().second + notes[__builtin_ctz(b)] <= p[i]) {
          vis[dp[i].front().first^LSOne(b)] = 1;
          dp[i].push_back({dp[i].front().first^LSOne(b), dp[i].front().second + notes[__builtin_ctz(b)]});
        }
        b -= LSOne(b);
      }
      dp[i].pop_front();
    }
  }

  if (dp[n].size()) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}
