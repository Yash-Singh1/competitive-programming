#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);

  int n;
  cin >> n;
  
  pair<pair<int, int>, int> a[n * 2];
  pair<pair<int, int>, int> b[n * 2];

  for (int i{0}; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    a[i * 2] = {{x, 1}, i * 2 + 1};
    b[i * 2] = {{x, 1}, i * 2 + 1};
    a[i * 2 + 1] = {{y, -1}, i * 2};
    b[i * 2 + 1] = {{y, -1}, i * 2};
  }

  sort(a, a + n * 2);

  int c{0};
  vector<pair<int, pair<int,int>>> v;
  int lst{a[0].first.first};
  int entire{0};
  for (int i{0}; i < n * 2; ++i) {
    if (c != 0) {
      entire += a[i].first.first - lst;
    }
    lst = a[i].first.first;
    c += a[i].first.second;
    if (c == 1) {
      v.push_back({-1, {a[i].first.first, -1}});
    } else {
      if (v.size() > 0 && v[v.size() - 1].first == -1 && c - a[i].first.second > 0) {
        v[v.size() - 1].second.second = a[i].first.first;
        v[v.size() - 1].first = a[i].first.first - v[v.size() - 1].second.first;
      }
      if (a[i].first.second == -1 && b[b[i].second].second > 1) {
        v.push_back({0, {0,0}});
      }
    }
    b[i].second = c;
  }

  int mn{INT_MAX};
  for (int i{0}; i < v.size(); ++i) {
    mn = min(mn, v[i].first);
  }

  cout << entire - mn;

  return 0;
}
