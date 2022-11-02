#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  set<int> cities;
  int x;
  for (int i{0}; i< n; ++i) {
    cin >> x;
    cities.insert(x);
  }
  set<int> towers;
  for (int i{0}; i < m; ++i) {
    cin >> x;
    towers.insert(x);
  }

  int minr{0};
  for (auto city: cities) {
    auto query = towers.lower_bound(city);
    // cout << city << " " << (query == towers.end() ? -1 : *query) << " " << (query == towers.begin() ? - 1 : *prev(query)) << "\n";
    minr = max(minr,min(
      query == towers.end() ? INT_MAX : abs((*query) - city),
      query == towers.begin() ? INT_MAX : abs(*prev(query) - city)
    )); 
  }

  cout << minr << "\n";

  return 0;
}
