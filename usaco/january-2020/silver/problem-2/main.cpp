#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("loan.in", "r", stdin);
  freopen("loan.out", "w", stdout);

  ll n, k, m;
  cin >> n >> k >> m;

  ll l{1}, r{n}, ans{-1};
  while (l <= r) {
    ll mid{(l+r)/2};
    ll cur{n}, ops{0};
    while (cur > 0 && ops < k) {
      if (cur / mid <= m) {
        ops += (cur + m - 1) / m;
        cur = 0;
        break;
      }
      ll div{cur / mid}, low{div*mid};
      ops += (cur - low) / div + 1;
      cur = ((cur - low) % div) + low - div;
    }
    if (cur <= 0 && ops <= k) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans << "\n";

  return 0;
}
