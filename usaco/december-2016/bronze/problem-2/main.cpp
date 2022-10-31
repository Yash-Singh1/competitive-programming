#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);

  int n;
  cin >> n;

  string s;
  int val[26], val2[26];
  int ans[26];
  for (int i{0}; i < 26; ++i) {
    ans[i]=0;
  }
  for (int i{0}; i < n; ++i) {
    for (int i{0}; i < 26; ++i) {
      val[i] = 0;
      val2[i] = 0;
    }
    cin >> s;
    for (auto &c: s) {
      ++val[c-'a'];
    }
    cin >> s;
    for (auto &c: s) {
      ++val2[c-'a'];
    }
    for (int i{0}; i < 26; ++i) {
      ans[i] += max(val[i],val2[i]);
    }
  }

  for (int i{0}; i < 26; ++i) {
    cout << ans[i] << "\n";
  }

  return 0;
}
