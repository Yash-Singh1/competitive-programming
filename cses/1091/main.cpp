#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  multiset<int> ms;
  for (int i{0}; i < n; ++i) {
    int x;
    cin >> x;
    ms.insert(x);
  }

  for (int i{0}; i < m; ++i) {
    int x;
    cin >> x;
    bool failure{false};
    if (!ms.empty()) {
      auto upp = ms.upper_bound(x);
      if (upp == ms.begin()) {
        failure = true;
      } else {
        --upp;
        cout << *upp << "\n";
        ms.erase(upp);
      }
    } else {
      failure = true;
    }
    if (failure) {
      cout << -1 << "\n";
    }
  }

  return 0;
}
