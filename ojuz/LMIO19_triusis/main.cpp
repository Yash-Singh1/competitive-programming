#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    a[i] = (m * (i + 1)) - a[i];
  }

  vector<int> lis;
  for (int i{0}; i < n; ++i) {
    if (a[i] < 0) continue;
    auto it = upper_bound(lis.begin(), lis.end(), a[i]);
    if (it == lis.end()) {
      lis.push_back(a[i]);
    } else {
      lis[it - lis.begin()] = a[i];
    }
  }

  cout << n - lis.size() << "\n";

  return 0;
}
