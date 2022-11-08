#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  bitset<150002>occ;

  map<int,int> a;
  int x;
  for (int i{0}; i < n; ++i) {
    cin >> x;
    ++a[x];
  }

  for (auto beg = a.begin(); beg != a.end(); ++beg) {
    int lim{(beg->first == 1 ? 1 : 2)};
    for (int i{beg->first == 1 ? 0 : -1}; i <= beg->second - lim && i < 2; ++i) {
      if (occ.test(beg->first+i)) {
        --lim;
      } else {
        occ.set(beg->first+i);
      }
    }
  }

  cout << occ.count() << "\n";

  return 0;
}
