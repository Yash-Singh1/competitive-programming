#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> g[n];
  int x;
  for (int i{0}; i < n; ++i) {
    cin >> x;
    --x;
    g[i].push_back(x);
    g[x].push_back(i);
  }

  bool visited[n];
  for (int i{0}; i < n; ++i) visited[i] = 0;
  int tots{0};
  for (int i{0}; i < n; ++i) {
    if (visited[i]) continue;
    stack<int> s;
    s.push(i);
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
    ++tots;
  }

  cout << tots << "\n";

  return 0;
}
