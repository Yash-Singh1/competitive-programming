// The reason that this fails even though it's iterative is because the number of loops
// is higher because the dynamic programming cache doesn't get updated when the graph
// is still in the process of being traversed.

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> dp(900000, -1);

int dfs(int start, vector<int> a[], int n) {
    vector<bool> visited(n, 0);
    if (dp[start] != -1) {
        return dp[start];
    }
    int tot{-1};
    stack<int> s;
    s.push(start);
    while (!s.empty()) {
        int now{s.top()};
        ++tot;
        visited[now] = 1;
        s.pop();
        for (auto neighbor: a[now]) {
            if (!visited[neighbor]) {
                if (dp[neighbor] != -1) {
                    tot += dp[neighbor];
                } else {
                    s.push(neighbor);
                }
            }
        }
    }
    dp[start] = tot;
    return tot;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  vector<int> a[n + 1];
  for (int i{2}; i <= n; ++i) {
    int x;
    cin >> x;
    a[x].push_back(i);
  }
  for (int i{1}; i <= n; ++i) {
    cout << dfs(i, a, n) << " ";
  }
}
