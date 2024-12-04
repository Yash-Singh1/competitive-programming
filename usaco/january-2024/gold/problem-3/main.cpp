#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;

  vector<ll> a(100001);
  cin >> t;
  vector<int> ans;

  while (t--) {
    cin >> n;
    for (int i{0}; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.begin() + n);

    ll mt{LLONG_MAX};
    for (int i{0}; i <= n; ++i) {
      int curb{i};
      ll nextinsert{i};
      ll curt{0};
      int l{0};
      while (l < n && curb > 0) {
        while (l < n-curb && a[l] < nextinsert) {
          l = prev(lower_bound(a.begin(), a.begin() + (n - curb), nextinsert)) - a.begin();
          curt = max(curt, a[l]);
          ++l;
        }
        curt = max(curt, nextinsert);
        ++l;
        --curb;
        nextinsert += curb;
      }
      while (l < n) {
        curt = max(curt, a[n-1]);
        l = n;
      }
      mt = min(mt, curt);
    }

    ans.push_back(mt);
  }

  for (auto &anse: ans) {
    cout << anse << '\n';
  }

  return 0;
}
