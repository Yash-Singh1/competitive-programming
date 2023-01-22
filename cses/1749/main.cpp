#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ordered_set s;
  int n, x;
  cin >> n;

  for (int i{0}; i < n; ++i) {
    cin >> x;
    s.insert({i, x});
  }

  for (int i{0}; i < n; ++i) {
    cin >> x; --x;
    cout << s.find_by_order(x)->second;
    if (i != n - 1) cout << " ";
    s.erase(s.find_by_order(x));
  }

  cout << "\n";

  return 0;
}
