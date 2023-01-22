#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  map<int,int> f;
  int r{0};
  ll ans{0};
  for (int l{0}; l < n; ++l) {
    while (r < n) {
      if ((int)f.size() == k && f.find(a[r]) == f.end()) break;
      ++f[a[r]];
      ++r;
    }
    ans += r - l;
    --f[a[l]];
    if (f[a[l]] == 0) f.erase(a[l]);
  }

  cout << ans << "\n";

  return 0;
}
