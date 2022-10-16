#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, n;
  cin >> x >> n;

  set<pair<int, pair<int, int>>> pq;
  set<pair<int, int>> s2;
  s2.insert({0, x});
  pq.insert({x, {0, x}});

  for (int i{0}; i < n; ++i) {
    int a;
    cin >> a;
    pair<int, int> lookup = {a, INT_MIN};
    auto anstry = s2.lower_bound(lookup);
    --anstry;
    pq.erase({anstry->second - anstry->first, *anstry});
    pq.insert({a - anstry->first, {anstry->first, a}});
    pq.insert({anstry->second - a, {a, anstry->second}});
    pair<int, int> ans = *anstry;
    s2.insert(anstry, {ans.first, a});
    s2.insert(++anstry, {a, ans.second});
    s2.erase(ans);
    cout << (--pq.end())->first << endl;
  }

  return 0;
}
