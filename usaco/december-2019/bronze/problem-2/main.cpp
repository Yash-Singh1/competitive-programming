#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);

  int n;
  cin >> n;
  string s;
  cin >> s;

  for (int k{1}; k <= n; ++k) {
    set<string> se;
    for (int i{0}; i < n - k + 1; ++i) {
      string a{s.substr(i, k)};
      if (se.find(a) != se.end()) {
        goto failure;
      }
      se.insert(a);
    }
    cout << k << "\n";
    return 0;
    failure: continue;
  }

  return 0;
}
