#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  long long n;
  cin >> n;
  map<long long, bool> m;

  long long mn{0};
  long long ans{0};
  long long cur{0};
  for (long long i{0}; i < n; ++i) {
    long long x;
    cin >> x;
    cur += x;
    if (i == 0) ans = cur - mn;
    ans = max(ans, cur - mn);
    mn = min(cur, mn);
  }

  cout << ans;

  return 0;
}
