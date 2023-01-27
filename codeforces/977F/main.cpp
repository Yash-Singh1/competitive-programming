#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  map<int,int> dp;
  int ans{0}, back{-1};
  for (int i{0}; i < n; ++i) {
    if (dp.find(a[i] - 1) == dp.end() || dp[a[i] - 1] + 1 > dp[a[i]]) {
      if (dp.find(a[i] - 1) == dp.end()) {
        dp[a[i]] = 1;
      } else {
        dp[a[i]] = dp[a[i] - 1] + 1;
      }
    }
    if (dp[a[i]] > ans) {
      ans = dp[a[i]];
      back = a[i];
    }
  }

  cout << ans << "\n";

  vector<int> anse(ans);
  int cure{0};
  for (int i{n - 1}; i >= 0; --i) {
    if (a[i] == back) {
      anse[cure] = i+1;
      ++cure;
      --back;
    }
  }

  reverse(anse.begin(), anse.end());

  for (auto &ansp: anse) {
    cout << ansp << " ";
  }
  cout << "\n";

  return 0;
}
