// Greedy fails here

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  multiset<int> m;
  int o;
  for (int i{0}; i < n*2; ++i) {
    cin >> o;
    m.insert(o);
  }

  int sm{0};
  for (int j{0}; j < n-1; ++j) {
    int mgap{INT_MAX};
    multiset<int>::iterator mgapit;
    for (auto it = m.begin(); it != prev(m.end()); it = next(it)) {
      int goodornot = abs(*it - *next(it));
      if (goodornot < mgap) {
        mgap = goodornot;
        mgapit = it;
      }
    }

    sm += mgap;
    m.erase(mgapit, next(next(mgapit)));
  }

  cout << sm << "\n";

  return 0;
}
