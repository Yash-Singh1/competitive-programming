#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> bb(n);
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  int x;
  for (int i{0}; i < n; ++i) {
    cin >> x;
    bb[x - 1] = i;
  }

  vector<int> lis;
  for (int i{0}; i < n; ++i) {
    auto it = lower_bound(lis.begin(), lis.end(), bb[a[i]]);
    if (it == lis.end()) {
      lis.push_back(bb[a[i]]);
    } else {
      lis[it - lis.begin()] = bb[a[i]];
    }
  }

  cout << lis.size() << "\n";

  return 0;
}
