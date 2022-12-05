#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("evolution.in", "r", stdin);
  freopen("evolution.out", "w", stdout);

  int n;
  cin >> n;

  set<string> s[n];

  int k;
  string x;
  set<string> se;
  for (int i{0}; i < n; ++i) {
    cin >> k;
    for (int j{0}; j < k; ++j) {
      cin >> x;
      s[i].insert(x);
      se.insert(x);
    }
  }

  for (auto it = se.begin(); it != se.end(); it = next(it)) {
    for (auto it2 = se.begin(); it2 != se.end(); it2 = next(it2)) {
      if (it2 != it) {
        bool one{0}, two{0}, three{0};
        set<string>::iterator query1, query2;
        for (int i{0}; i < n; ++i) {
          query1 = s[i].find(*it);
          query2 = s[i].find(*it2);
          if (query1 != s[i].end() && query2 == s[i].end()) {
            one = 1;
          } else if (query1 == s[i].end() && query2 != s[i].end()) {
            two = 1;
          } else if (query1 != s[i].end() && query2 != s[i].end()) {
            three = 1;
          }
        }
        if (one && two && three) {
          cout << "no\n";
          return 0;
        }
      }
    }
  }

  cout << "yes\n";

  return 0;
}
