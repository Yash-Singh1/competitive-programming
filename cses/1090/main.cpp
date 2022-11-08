#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  multiset<int> s;
  int y;
  for (int i{0}; i < n; ++i) {
    cin >> y;
    s.insert(y);
  }

  int tot{0};
  multiset<int>::iterator query;
  while (!s.empty()) {
    int taken{*s.rbegin()};
    s.erase(prev(s.end()));
    query = s.upper_bound(x-taken);
    if (query != s.begin() && !s.empty()) {
      taken += *prev(query);
      s.erase(prev(query));
    }
    ++tot;
  }

  cout << tot << "\n";

  return 0;
}
