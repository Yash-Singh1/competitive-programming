#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

set<pii> x, y;

void refresh(pii &a, int &k) {
  if (k <= 1) {
    x.insert(a);
    y.insert({a.second, a.first});
  } else {
    y.insert(a);
    x.insert({a.second, a.first});
  }
}

pii rm(int &k) {
  pii ans;
  if (k == 0) {
    ans = *x.begin();
    y.erase({ans.second, ans.first});
    x.erase(x.begin());
  } else if (k == 1) {
    ans = *prev(x.end());
    y.erase({ans.second, ans.first});
    x.erase(prev(x.end()));
  } else if (k == 2) {
    ans = *y.begin();
    x.erase({ans.second, ans.first});
    y.erase(y.begin());
  } else {
    ans = *prev(y.end());
    x.erase({ans.second, ans.first});
    y.erase(prev(y.end()));
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("reduce.in", "r", stdin);
  freopen("reduce.out", "w", stdout);

  int n;
  cin >> n;

  int a, b;
  for (int i{0}; i < n; ++i) {
    cin >> a >> b;
    x.insert({a, b});
    y.insert({b, a});
  }

  int ans{(x.rbegin()->first - x.begin()->first) * (y.rbegin()->first - y.begin()->first)};
  for (int i{0}; i < 4; ++i) {
    pii rmed = rm(i);
    for (int j{0}; j < 4; ++j) {
      pii rmed2 = rm(j);
      for (int k{0}; k < 4; ++k) {
        pii rmed3 = rm(k);
        ans = min(ans, (x.rbegin()->first - x.begin()->first) * (y.rbegin()->first - y.begin()->first));
        refresh(rmed3, k);
      }
      refresh(rmed2, j);
    }
    refresh(rmed, i);
  }

  cout << ans << "\n";

  return 0;
}
