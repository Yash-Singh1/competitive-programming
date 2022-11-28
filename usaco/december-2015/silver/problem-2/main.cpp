#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("highcard.in", "r", stdin);
  freopen("highcard.out", "w", stdout);

  int n;
  cin >> n;

  bool exists[n*2];
  for (int i{0}; i < 2*n; ++i) {
    exists[i] = 1;
  }

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    exists[a[i]-1] = 0;
  }

  set<int> s;
  for (int i{1}; i <= 2*n; ++i) {
    if (exists[i-1]) {
      s.insert(i);
    }
  }

  int points{0};
  for (int i{0}; i < n; ++i) {
    auto query = s.upper_bound(a[i]);
    if (query == s.end()) {
      s.erase(s.begin());
    } else {
      s.erase(query);
      ++points;
    }
  }
  cout << points << "\n";

  return 0;
}
