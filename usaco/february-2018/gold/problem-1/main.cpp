#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("snowboots.in", "r", stdin);
  freopen("snowboots.out", "w", stdout);

  int n, b;
  cin >> n >> b;

  if (n < 3) {
    while (b--) cout << 1 << "\n";
    return 0;
  }

  vector<pair<int,int>> tiles(n);
  for (int i{0}; i < n; ++i) {
    cin >> tiles[i].first;
    tiles[i].second = i;
  }
  sort(tiles.begin(), tiles.end(), greater<pair<int,int>>());

  set<int> val;
  for (int i{0}; i < n; ++i) {
    val.insert(i);
  }

  int gap{1};
  map<int,int> gap2m;
  gap2m[n-1] = 0;
  for (int i{0}; i < n; ++i) {
    auto query = val.find(tiles[i].second);
    gap2m[gap] = tiles[i].first;
    if (val.size() == 1) {
      gap = n - 2;
    } else if (query == val.begin()) {
      gap = max(gap, *next(query) - 1);
    } else if (next(query) == val.end()) {
      gap = max(gap, (n - 2) - *prev(query));
    } else {
      gap = max(gap, *next(query) - *prev(query));
    }
    val.erase(query);
  }

  int depth, size;
  for (int i{0}; i < b; ++i) {
    cin >> depth >> size;
    if (size >= n-1) {
      cout << 1 << "\n";
    } else {
      cout << ((prev(gap2m.upper_bound(size))->second) <= depth) << "\n";
    }
  }

  return 0;
}
