#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  
  int x;
  int f;
  cin >> x;
  list<pair<int,int>> edges;
  for (int i{1}; i < n; ++i) {
    cin >> x;
    if (i == 1) f = x;
    edges.push_back({1, x});
  }
  cin >> x;
  int y;
  for (int i{1}; i < n; ++i) {
    y = x;
    cin >> x;
    if (i == 1) {
        if (f != x) {
          cout << -1 << '\n';
          return 0;
        }
    } else {
        edges.push_back({y, x});
    }
  }
  
  cout << edges.size() << '\n';
  for (auto &edge: edges) {
      cout << edge.first << ' ' << edge.second << '\n';
  }

  return 0;
}
