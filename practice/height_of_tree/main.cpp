#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> g[1000];

int height(int root, int p) {
  int h{0};
  for (auto &ne: g[root]) {
    if (ne != p) {
      h = max(h, height(ne, root) + 1);
    }
  }
  return h;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  int x, y;
  for (int i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  cout << height(0, -1) << "\n";

  return 0;
}
