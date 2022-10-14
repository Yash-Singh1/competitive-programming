#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;

  pair<long long, long long> a[n];
  for (long long i{0}; i < n; ++i) {
    pair<long long, long long> x;
    cin >> x.first >> x.second;
    a[i] = x;
  }

  long long locs[n][n];
  for (long long i{0}; i < n; ++i) {
    for (long long j{0}; j < n; ++j) {
      locs[i][j] = 0;
    }
  }
  
  sort(a, a + n);
  for (long long i{0}; i < n; ++i) {
    a[i].first = i;
  }
  sort(a, a + n, [](auto &left, auto &right) {
    return left.second < right.second;
  });
  for (long long i{0}; i < n; ++i) {
    a[i].second = i;
    locs[a[i].first][i] = 1;
  }
  for (long long i{0}; i < n; ++i) {
    for (long long j{0}; j < n; ++j) {
      if (i != 0) {
        locs[i][j] += locs[i - 1][j];
      }
      if (j != 0) {
        locs[i][j] += locs[i][j - 1];
      }
      if (i != 0 && j != 0) {
        locs[i][j] -= locs[i - 1][j - 1];
      }
    }
  }

  long long pos{n + 1};
  for (long long i{0}; i < n; ++i) {
    for (long long j{i + 1}; j < n; ++j) {
      long long x1 = a[i].first;
      long long x2 = a[j].first;
      long long y1 = a[i].second;
      long long y2 = a[j].second;
      if (x2 < x1) {
        long long s{x2};
        x2 = x1;
        x1 = s;
      }
      pos += ((x2 != n - 1 ? (locs[n - 1][y2] - locs[x2][y2] - (y1 != 0 ? (locs[n - 1][y1 - 1] - locs[x2][y1 - 1]) : 0)) : 0) + 1)
        * ((x1 != 0 ? (locs[x1 - 1][y2] - (y1 != 0 ? locs[x1 - 1][y1 - 1] : 0)) : 0) + 1);
    }
  }
  cout << pos << "\n";
}
