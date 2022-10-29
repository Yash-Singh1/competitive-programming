#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);

  int n;
  cin >> n;

  pair<int,int>a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }

  int ans{0};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      for (int k{0}; k < n; ++k) {
        if (i != j && j != k && i != k) {
          // i : origin, j : top/bottom, k : right/left
          if (a[i].second == a[k].second && a[j].second != a[i].second && a[i].first == a[j].first && a[i].first != a[k].first) {
            ans = max(abs(a[j].second - a[i].second) * abs(a[k].first - a[i].first), ans);
          }
        }
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
