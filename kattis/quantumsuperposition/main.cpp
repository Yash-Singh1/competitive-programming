#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n1, n2, m1, m2;
  cin >> n1 >> n2 >> m1 >> m2;

  vector<vector<bool>> dp1(n1, vector<bool>(1000)), dp2(n2, vector<bool>(1000));
  vector<vector<int>> g1(n1), g2(n2);
  vector<int> in1(n1), in2(n2);
  int a, b;
  for (int i{0}; i < m1; ++i) {
    cin >> a >> b;
    --a; --b;
    ++in1[b];
    g1[a].push_back(b);
  }
  for (int i{0}; i < m2; ++i) {
    cin >> a >> b;
    --a; --b;
    ++in2[b];
    g2[a].push_back(b);
  }

  stack<int> s;
  dp1[0][0] = 1;
  for (int i{0}; i < n1; ++i) {
    if (!in1[i]) s.push(i);
  }
  while (s.size()) {
    int u = s.top();
    s.pop();
    for (auto &v: g1[u]) {
      --in1[v];
      for (int i{0}; i < 1000; ++i) {
        if (dp1[u][i]) {
          dp1[v][i + 1] = 1;
        }
      }
      if (!in1[v]) {
        s.push(v);
      }
    }
  }

  dp2[0][0] = 1;
  for (int i{0}; i < n2; ++i) {
    if (!in2[i]) s.push(i);
  }
  while (s.size()) {
    int u = s.top();
    s.pop();
    for (auto &v: g2[u]) {
      --in2[v];
      for (int i{0}; i < 1000; ++i) {
        if (dp2[u][i]) {
          dp2[v][i + 1] = 1;
        }
      }
      if (!in2[v]) {
        s.push(v);
      }
    }
  }

  vector<bool> dp(2001);
  for (int i{0}; i < 1000; ++i) {
    for (int j{0}; j < 1000; ++j) {
      if (dp1[n1-1][i] && dp2[n2-1][j]) dp[i + j] = 1;
      else if (dp1[n1-1][j] && dp2[n2-1][i]) dp[i + j] = 1;
    }
  }

  int q, x;
  cin >> q;
  while (q--) {
    cin >> x;
    if (dp[x]) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}
