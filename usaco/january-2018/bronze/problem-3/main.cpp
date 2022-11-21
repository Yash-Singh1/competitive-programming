#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("outofplace.in", "r", stdin);
  freopen("outofplace.out", "w", stdout);

  int n;
  cin >> n;

  int a[n], b[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b,b+n);
  set<int> s;
  for (int i{0}; i < n; ++i) {
    if (a[i] != b[i]) {
      s.insert(a[i]);
    }
  }

  cout << s.size() - 1 << "\n";

  return 0;
}
