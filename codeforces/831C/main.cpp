#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, n;
  cin >> k >> n;

  int a[k];
  for (int i{0}; i < k; ++i) {
    cin >> a[i];
  }

  int b[n];
  for (int i{0}; i < n; ++i) {
    cin >> b[i];
  }
  sort(b,b+n);

  for (int i{1}; i < k; ++i) {
    a[i] += a[i-1];
  }
  sort(a,a+k);

  set<int> ans;
  for (int i{0}; i <= k-n; ++i) {
    multiset<int>s;
    for (int j{0}; j < n; ++j) {
      s.insert(b[j]);
    }
    for (int j{i}; j < k && !s.empty(); ++j) {
      if (s.find((b[0]-a[i]) + a[j]) != s.end()) {
        s.erase(s.find((b[0]-a[i]) + a[j]));
      }
    }
    if (s.empty()) {
      ans.insert(b[0]-a[i]);
    }
  }

  cout << ans.size() << "\n";

  return 0;
}
