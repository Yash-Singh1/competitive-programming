#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> mdiv(200001);
  for (int i{2}; i <= 200000; ++i) {
    if (mdiv[i] != 0) continue;
    for (int j{i}; j <= 200000; j += i) {
      mdiv[j] = i;
    }
  }

  unordered_map<ll,int> m;
  int x;
  for (int i{0}; i < n; ++i) {
    cin >> x;
    while (x > 1) {
      int tot{0};
      int prim{mdiv[x]};
      while (mdiv[x] == prim && x % mdiv[x] == 0) {
        ++tot;
        ++m[((ll)prim << 22) + tot];
        x /= mdiv[x];
      }
    }
  }

  vector<int> best(200001);
  for (auto it = m.begin(); it != m.end(); it = next(it)) {
    if (it->second < n - 1) continue;
    best[(it->first)>>22] = max((int)(it->first & ((1<<20)-1)), best[(it->first)>>22]);
  }

  ll ans{1};
  for (int i{1}; i <= 200000; ++i) {
    if (best[i]) {
      for (int j{0}; j < best[i]; ++j) {
        ans *= i;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
