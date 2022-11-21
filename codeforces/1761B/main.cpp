// WA on prelim TC 3

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (int i{0}; i < n; ++i) {
      cin >> a[i];
    }
    if (n <= 2) {
      cout << n << "\n";
      continue;
    }
    int tot{0};
    while (a.size() > 2) {
      bool alreadyg{0};
      for (int i{0}; i < a.size(); ++i) {
        if (a[(i+2)%a.size()] == a[i]) {
          a.erase(a.begin() + i);
          alreadyg = 1;
          break;
        }
      }
      if (!alreadyg) {
        a.pop_back();
      } else {
        bool found{1};
        while (found) {
          found = 0;
          for (int i{0}; i < a.size(); ++i) {
            if (a[i] == a[(i + 1) % a.size()]) {
              found = 1;
              a.erase(a.begin() + i);
            }
          }
        }
      }
      ++tot;
    }
    cout << tot+a.size() << "\n";
  }

  return 0;
}
