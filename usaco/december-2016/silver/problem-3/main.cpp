#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);

  int n;
  cin >> n;

  pair<pair<int,int>, int> a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i].first.first >> a[i].first.second >> a[i].second;
  }

  vector<int> g[n];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (sqrt(pow(a[j].first.first - a[i].first.first, 2) + pow(a[j].first.second - a[i].first.second, 2)) <= a[i].second) {
        g[i].push_back(j);
      }
    }
  }

  bool visited[n];
  int ans{0};
  for (int i{0}; i < n; ++i) {
    stack<int> s;
    s.push(i);
    for (int j{0}; j < n; ++j) {
      visited[j]=0;
    }
    while (!s.empty()) {
      int stop{s.top()};
      s.pop();
      visited[stop] = 1;
      for (auto &ne: g[stop]) {
        if (!visited[ne]) {
          s.push(ne);
        }
      }
    }
    int tot{0};
    for (int i{0};i < n; ++i) {
      if (visited[i]) {
        ++tot;
      }
    }
    ans = max(ans, tot);
  }

  cout << ans << "\n";

  return 0;
}
