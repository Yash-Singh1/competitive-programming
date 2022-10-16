#include <bits/stdc++.h>

using namespace std;

bool compareInterval(pair<int, int> i1, pair<int, int> i2)
{
    if (i1.first != i2.first) {
      return i1.first < i2.first;
    } else {
      return i1.second < i2.second;
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  pair<int, int> a[n * 2];
  for (int i{0}; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    a[i * 2] = {x, 1};
    a[i * 2 + 1] = {y, -1};
  }
  sort(a, a + (n * 2), compareInterval);

  int c{0};
  int mxppl{0};
  for (int i{0}; i < (n * 2); ++i) {
    c += a[i].second;
    if (c > mxppl) {
      mxppl = c;
    }
  }

  cout << mxppl;

  return 0;
}
