#include <bits/stdc++.h>

using namespace std;

int n;
vector<bool> a(200000);
vector<int> memo(200000);

int skips(int pos) {
  assert(pos <= n);
  if (pos == n) {
    return 0;
  }
  if (memo[pos] != -1) {
    return memo[pos];
  }
  int ans{INT_MAX};
  for (int i{0}; i < 2 && pos + i < n; ++i) {
    if (pos + i + 1 == n) {
      int skipee{0};
      if (a[pos]) {
        ++skipee;
      }
      if (i == 1 && a[pos + i]) {
        ++skipee;
      }
      ans = min(skipee, ans);
    }
    for (int j{0}; j < 2 && pos + i + j + 1 < n; ++j) {
      int skipee{0};
      if (a[pos]) {
        ++skipee;
      }
      if (i == 1 && a[pos + i]) {
        ++skipee;
      }
      skipee += skips(pos + i + j + 2);
      ans = min(skipee, ans);
    }
  }
  memo[pos] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("input.in", "r", stdin);
  // freopen("input.out", "w", stdout);

  int t;
  char x;
  cin >> t;

  while (t--) {
    cin >> n;
    for (int i{0}; i < n; ++i) {
      cin >> x;
      if (x == '1') {
        a[i] = 1;
      } else {
        a[i] = 0;
      }
      memo[i] = -1;
    }
    cout << skips(0) << "\n";
  }

  return 0;
}
