#include <bits/stdc++.h>

using namespace std;

int n;
int val[1000];

int smLeafNodes(int root, int p, vector<int> g[]) {
  int sm{0};
  bool child{0};
  for (auto &ne: g[root]) {
    if (ne != p) {
      child = 1;
      sm += smLeafNodes(ne, root, g);
    }
  }
  if (child) {
    return sm;
  }
  return val[root];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i{0}; i < n; ++i) {
    cin >> val[i];
  }

  vector<int> g[n];
  int x, y;
  for (int i{1}; i < n; ++i) {
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  cout << smLeafNodes(0, -1, g) << "\n";

  return 0;
}
