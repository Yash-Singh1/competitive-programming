#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> g(n);

  vector<int> preorder;
  stack<pii> s;
  s.push({0, -1});
  while (s.size()) {
    int u = s.top().first;
    int p = s.top().second;
    s.pop();
    preorder.push_back(u);
    for (auto &v: g[u]) {
      if (v != p) {
        s.push({v, u});
      }
    }
  }

  // Print out preorder or use it for whatever purpose...

  return 0;
}
