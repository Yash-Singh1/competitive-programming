#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("cardgame.in", "r", stdin);
  freopen("cardgame.out", "w", stdout);

  int n;
  cin >> n;

  bool exists[2*n];
  for (int i{0}; i < 2*n; ++i) {
    exists[i] = 1;
  }
  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    exists[a[i] - 1] = 0;
  }

  int points{0};

  set<int> s;
  for (int i{0}; i < n/2; ++i) {
    s.insert(a[i]);
  }

  set<int> s2;
  for (int i{n/2}; i < n; ++i) {
    s2.insert(a[i]);
  }

  int iterated{0};
  for (int i{2*n-1}; i >= 0; --i) {
    if (exists[i]) {
      if (iterated < (n/2)) {
        auto query = s.upper_bound(i+1);
        if (query != s.begin()) {
          s.erase(prev(query));
          ++points;
        } else {
          s.erase(prev(s.end()));
        }
        ++iterated;
      } else {
        auto query = s2.upper_bound(i+1);
        if (query == s2.end()) {
          s2.erase(s2.begin());
        } else {
          s2.erase(query);
          ++points;
        }
      }
    }
  }

  cout << points << "\n";

  return 0;
}
