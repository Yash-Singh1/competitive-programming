#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  vector<vector<int>> sms(n + 1, vector<int>(100001));
  sms[0][0] = 1;
  set<int> s;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j <= 100000; ++j) {
      if (sms[i][j] > 0) {
        sms[i + 1][j + a[i]] = 1;
        sms[i + 1][j] = 1;
        s.insert(j + a[i]);
      }
    }
  }

  cout << s.size() << "\n";
  while (!s.empty()) {
    cout << *s.begin() << " ";
    s.erase(s.begin());
  }
  cout << "\n";

  return 0;
}
