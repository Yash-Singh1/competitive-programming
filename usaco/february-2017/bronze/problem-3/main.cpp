#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out", "w", stdout);

  int n;
  cin >> n;

  pair<int,int> a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }

  sort(a,a+n);

  int t{0};
  for (int i{0}; i < n; ++i) {
    if (t < a[i].first) {
      t = a[i].first;
    }
    t += a[i].second;
  }

  cout << t << "\n";

  return 0;
}
