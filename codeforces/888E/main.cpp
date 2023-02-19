#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  set<int> s;
  for (int i{(1<<(n/2))-1}; i >= 0; --i) {
    int sm{0};
    for (int j{0}; j < n/2; ++j) {
      if (i&(1<<j)) {
        sm += a[j];
        sm %= m;
      }
    }
    s.insert(sm);
  }

  int mx{0};
  for (int i{(1<<(n-(n/2)))-1}; i >= 0; --i) {
    int sm{0};
    for (int j{n/2}; j < n; ++j) {
      if (i&(1<<(j-n/2))) {
        sm += a[j];
        sm %= m;
      }
    }
    auto it = s.upper_bound(m-sm-1);
    if (it == s.begin() || s.empty()) {
      mx = max(mx, sm);
    }
    mx = max(mx, sm + (*prev(it)));
  }

  cout << mx << "\n";

  return 0;
}
