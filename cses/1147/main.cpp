#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<char>> a(n, vector<char>(m));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> h(n, vector<int>(m));
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < m; ++j) {
      if (a[i][j] == '*') {
        h[i][j] = 0;
      } else {
        if (i == 0) h[i][j] = 1;
        else h[i][j] = h[i - 1][j] + 1;
      }
    }
  }

  int ans{0};
  for (int j{0}; j < n; ++j) {
    stack<pair<int,int>> s;
    vector<int> mrec(m);
    for (int i{0}; i < m; ++i) {
      while (s.size() && s.top().first >= h[j][i]) {
        s.pop();
      }
      if (s.size()) {
        mrec[i] = h[j][i] * (i - s.top().second);
      } else {
        mrec[i] = h[j][i] * (i + 1);
      }
      s.push({h[j][i], i});
    }
    stack<pair<int,int>> b;
    for (int i{m - 1}; i >= 0; --i) {
      while (b.size() && b.top().first >= h[j][i]) {
        b.pop();
      }
      if (b.size()) {
        mrec[i] += h[j][i] * (b.top().second - i - 1);
      } else {
        mrec[i] += h[j][i] * (m - i - 1);
      }
      ans = max(mrec[i], ans);
      b.push({h[j][i], i});
    }
  }

  cout << ans << "\n";

  return 0;
}
