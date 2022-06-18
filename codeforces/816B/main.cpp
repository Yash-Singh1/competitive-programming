// Gives a TLE, have to use Binary Search, but uses Sweep Line Algorithm

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k, q;
  cin >> n >> k >> q;
  pair<long long, long long> recipes[n];
  for (long long i{0}; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    recipes[i] = make_pair(x, y);
  }
  for (long long i{0}; i < q; ++i) {
    long long x, y;
    cin >> x >> y;
    long long a[y - x + 1];
    for (long long j{0}; j < y - x + 1; ++j) {
      a[j] = 0;
    }
    for (long long j{0}; j < n; ++j) {
      if (recipes[j].second >= x && recipes[j].first <= y) {
        a[max(recipes[j].first, x) - x]++;
        if (y > recipes[j].second) {
          a[recipes[j].second - x + 1]--;
        }
      }
    }
    long long ans{0};
    for (long long j{0}; j < y - x + 1; ++j) {
      if (j > 0) {
        a[j] += a[j - 1];
      }
      if (a[j] >= k) {
        ++ans;
      }
    }
    cout << ans << "\n";
  }
}
