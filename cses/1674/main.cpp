#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> dp(900000, -1);
vector<int> a[900000];

int dfs(int start, vector<int> a[]) {
    if (dp[start] != -1) {
        return dp[start];
    }
    int tot{0};
    for (auto child: a[start]) {
        tot += dfs(child, a) + 1;
    }
    dp[start] = tot;
    return tot;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i{2}; i <= n; ++i) {
    int x;
    cin >> x;
    a[x].push_back(i);
  }
  for (int i{1}; i <= n; ++i) {
    cout << dfs(i, a) << " ";
  }
}
