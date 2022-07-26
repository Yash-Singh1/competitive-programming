// WA, because selects domino in furthest reach
// can't find efficient solution to select domino with highest knockover in reach

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  pair<int, int> a[n];
  int b[n];
  for (int i{0}; i < n; ++i) {
    int x, h;
    cin >> x >> h;
    a[i] = {x, h};
    b[i] = x;
  }
  long long dist[n];
  dist[n - 1] = 1;
  for (int i{n - 2}; i >= 0; --i) {
    if (a[i].second >= (a[i + 1].first - a[i].first)) {
      auto loc = upper_bound(b + i + 1, b + n, (a[i].first + a[i].second)) - b;
      dist[i] = (loc - i) + dist[loc];
    } else {
      dist[i] = 1;
    }
  }
  for (int i{0}; i < n; ++i) {
    cout << dist[i] << " ";
  }
}
