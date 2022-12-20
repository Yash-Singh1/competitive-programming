#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n;

  bool primee[1000001];
  for (int i{0}; i <= 1000000; ++i) {
    primee[i] = 1;
  }
  for (int i{2}; i <= 1000; ++i) {
    if (!primee[i]) continue;
    for (int j{i*i}; j <= 1000000; j += i) {
      primee[j] = 0;
    }
  }
  set<int> prime;
  for (int i{2}; i <= 1000000; ++i) {
    if (primee[i]) {
      prime.insert(i);
    }
  }

  while (n--) {
    cin >> x;
    int ans{1};
    for (auto it = prime.begin(); (it != prime.end()) && !primee[x]; it = next(it)) {
      if ((x % (*it)) == 0) {
        int tot{1};
        while ((x % (*it)) == 0) {
          x /= (*it);
          ++tot;
        }
        ans *= tot;
      }
    }
    if (x > 1) ans *= 2;
    cout << ans << "\n";
  }

  return 0;
}
