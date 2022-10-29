#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  int n, b;
  cin >> n >> b;
  pair<int,int> a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }

  int ans{INT_MAX};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      int l1{0}, r1{0}, l2{0}, r2{0};
      for (int k{0}; k < n; ++k) {
        if (a[k].first < a[i].first) {
          if (a[k].second < a[j].second) {
            ++l1;
          } else {
            ++l2;
          }
        } else {
          if (a[k].second < a[j].second) {
            ++r1;
          } else {
            ++r2;
          }
        }
      }
      ans = min(ans,max(max(l1,l2),max(r1,r2)));
    }
  }

  cout << ans << "\n";

  return 0;
}
