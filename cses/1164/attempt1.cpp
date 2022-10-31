#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first == b.first.first) {
    if (a.second == b.second) {
      return a.first.second > b.first.second;
    }
    return a.first.second > b.first.second;
  } else {
    return a.first.first < b.first.first;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  pair<pair<int, int>, int> a[n * 2];
  for (int i{0}; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    a[i * 2].second = i;
    a[i * 2 + 1].second = i;
    a[i * 2].first = {x, 1};
    a[i * 2 + 1].first = {y, -1};
  }
  sort(a, a + n * 2, cmp);

  int c{0};
  int mx{0};
  int o[n];
  for (int i{0}; i < n * 2; ++i) {
    c += a[i].first.second;
    if (a[i].first.second == 1) {
      o[a[i].second] = c;
    }
    mx = max(c, mx);
  }

  cout << mx << "\n";
  for (int i{0}; i < n; ++i) {
    cout << o[i] << " ";
  }

  return 0;
}
