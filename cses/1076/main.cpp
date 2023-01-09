#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  // median advance k - 1 / 2
  ordered_set s;
  for (int i{0}; i < k; ++i) {
    s.insert({a[i], i});
  }
  for (int i{0}; i < n - k + 1; ++i) {
    // for (auto it = s.begin(); it != s.end(); it = next(it)) {
    //   cout << *it << " ";
    // }
    // cout << "\n";
    cout << s.find_by_order((k - 1) / 2)->first << " ";
    s.insert({a[i + k], i + k});
    s.erase(s.find({a[i], i}));
  }
  cout << "\n";

  return 0;
}
