#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<int, int> m;
  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }
  for (int i{0}; i < n; ++i) {
    int x;
    cin >> x;
    m[x] = i;
  }
  int mx{-1};
  int ans{0};
  for (int i{0}; i < n; ++i) {
    if (m[a[i]] > mx) {
      mx = m[a[i]];
    } else {
      ++ans;
    }
  }
  cout << ans;
}
