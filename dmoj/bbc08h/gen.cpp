// Bubble Cup V8 H Bots

#include <bits/stdc++.h>

using namespace std;

int n;

int tot(int cur, int bl, int re) {
  if (cur == 2*n) {
    return 1;
  }
  int total{0};
  if (bl != n) {
    total += tot(cur + 1, bl + 1, re);
  }
  if (re != n) {
    total += tot(cur + 1, bl, re + 1);
  }
  return total + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i{1}; i <= 5; ++i) {
    n = i;
    cout << tot(0, 0, 0) << " ";
  }
  cout << "\n";

  return 0;
}
