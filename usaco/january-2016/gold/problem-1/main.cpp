#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    a[i] <<= 1;
  }
  sort(a.begin(), a.end());

  vector<int> left(n), right(n);
  for (int i{1}; i < n; ++i) {
    left[i] = max(left[i - 1] + 1, a[i] - a[i-1]);
  }
  for (int i{n-2}; i >= 0; --i) {
    right[i] = max(right[i + 1] + 1, a[i + 1] - a[i]);
  }

  ll l{1}, r{(ll)2e9}, ans{-1};
  bool suc{1};
  while (l<=r) {
    ll p{(l+r)/2};
    // p = power
    ll l2{a[0]}, r2{a[n-1]}, ans2{a[0]};
    while (l2<=r2) {
      ll pos{(l2+r2)/2};
      // pos = position from left
      ll cur{pos};
      ll curp{p};
      suc = 1;
      while (cur >= 0) {
        if (lower_bound(a.begin(), a.end(), cur) == a.begin() || lower_bound(a.begin(), a.end(), cur-curp) == a.begin()) {
          break;
        }
        if (curp < 0) {
          suc = 0;
          break;
        }
        if (*lower_bound(a.begin(), a.end(), cur - curp) >= cur) {
          suc = 0;
          break;
        }
        cur = *lower_bound(a.begin(), a.end(), cur - curp);
        curp -= 2;
      }
      if (suc) {
        l2 = pos+1;
        ans2 = pos;
      } else {
        r2 = pos-1;
      }
    }
    suc = 1;
    ll cur{ans2}, curp{p};
    while (cur <= (ll)2e9) {
      if (upper_bound(a.begin(), a.end(), cur) == a.end() || upper_bound(a.begin(), a.end(), cur+curp) == a.end()) {
        break;
      }
      if (curp < 0) {
        suc = 0;
        break;
      }
      if (*prev(upper_bound(a.begin(), a.end(), cur+curp)) <= cur) {
        suc = 0;
        break;
      }
      cur = *prev(upper_bound(a.begin(), a.end(), cur+curp));
      curp -= 2;
    }
    if (suc) {
      ans = p;
      r = p-1;
    } else {
      l = p+1;
    }
  }

  cout << (ans/2) << "." << ((ans&1)*5) << "\n";

  return 0;
}
