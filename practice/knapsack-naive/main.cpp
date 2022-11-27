#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int w = 75;
  pair<int,int> arr[5] = {{80, 15}, {80, 40}, {20, 30}, {45, 35}, {30, 30}};

  int mx{0};
  for (int i{0}; i < (1<<5)-1; ++i) {
    int sm{0};
    int c{0};
    for (int j{0}; j < 5; ++j) {
      if (i&(1<<j)) {
        c += arr[j].second;
        if (c > 75) {
          goto nx;
        } else {
          sm += arr[j].first;
        }
      }
    }
    mx = max(sm, mx);
    nx: continue;
  }

  cout << mx << "\n";

  return 0;
}
