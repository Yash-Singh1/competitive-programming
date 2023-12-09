#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> seq;
  seq.reserve(n);
  int mx{0};
  for (int j{0}; j < 2; ++j) {
    for (int i{0}; i < n; ++i) {
      auto it = upper_bound(seq.begin(), seq.end(), a[i]);
      if (it == seq.end()) {
        seq.push_back(a[i]);
      } else {
        seq[it - seq.begin()] = a[i];
      }
    }
    mx = max(mx, (int)seq.size());
    seq.clear();
    seq.reserve(n);
    reverse(a.begin(), a.end());
  }

  cout << n-mx << '\n';

  return 0;
}
