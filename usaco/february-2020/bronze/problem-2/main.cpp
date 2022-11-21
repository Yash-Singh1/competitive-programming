#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("breedflip.in", "r", stdin);
  freopen("breedflip.out", "w", stdout);

  int n;
  cin >> n;

  bool a[n];
  bool b[n];

  char x;
  for (int i{0}; i < n; ++i) {
    cin >> x;
    if (x == 'H') {
      a[i] = 1;
    } else {
      a[i] = 0;
    }
  }
  for (int i{0}; i < n; ++i) {
    cin >> x;
    if (x == 'H') {
      b[i] = 1;
    } else {
      b[i] = 0;
    }
  }

  int tot{0};
  for (int i{0}; i < n; ++i) {
    if ((i == 0 && a[i] != b[i]) || (i != 0 && a[i] != b[i] && a[i-1] == b[i-1])) {
      ++tot;
    }
  }

  cout << tot << "\n";

  return 0;
}
