#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a; int x;
  a.reserve(n);
  for (int i{0}; i < n; ++i) {
    cin >> x;
    auto it = lower_bound(a.begin(), a.end(), x);
    if (it == a.end()) {
      a.push_back(x);
    } else {
      a[it - a.begin()] = x;
    }
  }

  cout << a.size() << '\n';

  return 0;
}
