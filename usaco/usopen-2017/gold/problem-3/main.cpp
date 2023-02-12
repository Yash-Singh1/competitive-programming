#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("art2.in", "r", stdin);
  freopen("art2.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  vector<int> mn(n+1, -1), mx(n+1, -1);
  vector<int> intervalmn(n, -1), intervalmx(n, -1);
  for (int i{0}; i < n; ++i) {
    if (mn[a[i]] == -1) {
      mn[a[i]] = i;
      if (a[i]) intervalmn[i] = a[i];
    }
    mx[a[i]] = i;
  }

  for (int i{1}; i <= n; ++i) {
    if (mx[i] != -1) {
      intervalmx[mx[i]] = i;
    }
  }

  stack<int> s;
  int ans{0};
  for (int i{0}; i < n; ++i) {
    if (intervalmn[i] != -1) {
      s.push(a[i]);
    }
    if (!a[i]) {
      if (s.size()) {
        cout << "-1\n";
        return 0;
      }
    }
    ans = max(ans, (int)s.size());
    if (intervalmx[i] != -1) {
      if (s.top() == intervalmx[i]) {
        s.pop();
      } else {
        cout << "-1\n";
        return 0;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
