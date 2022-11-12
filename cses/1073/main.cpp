#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  multiset<int>s;

  for (int i{0}; i < n; ++i) {
    multiset<int>::iterator query = s.upper_bound(a[i]);
    if (query != s.end()) {
      s.erase(query);
    }
    s.insert(a[i]);
  }

  cout << s.size() << "\n";

  return 0;
}
