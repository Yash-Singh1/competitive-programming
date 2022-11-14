#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("hoofball.in", "r", stdin);
  freopen("hoofball.out", "w", stdout);

  int n;
  cin >> n;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }
  sort(a,a+n);

  int g[n];
  for (int i{0}; i < n; ++i) {
    if (i == 0) {
      if (n == 1) g[i] = -1;
      else g[i] = 1;
    } else if (i == n - 1) {
      if (n == 1) g[i] = -1;
      else g[i] = n-2;
    } else if (a[i] - a[i-1] <= a[i+1]-a[i]) {
      g[i] = i-1;
    } else {
      g[i] = i+1;
    }
  }

  bool covered[n];
  for (int i{0}; i < n; ++i) {
    covered[i] = 0;
  }

  int pos{0};
  for (int i{0}; i < n; ++i) {
    if (covered[i]) continue;
    bool passesto{0};
    for (int j{0}; j < n; ++j) {
      if (i != j && g[j] == i) {
        passesto = 1;
      }
    }
    if (!passesto) {
      int position{i};
      for (int j{0}; j < n; ++j) {
        position = g[position];
        if (position != -1) {
          covered[position] = 1;
        }
      }
      ++pos;
    }
  }

  for (int i{0}; i < n; ++i) {
    if (covered[i]) {
      continue;
    }
    bool passesleft{0}, passesright{0};
    for (int j{0}; j < n; ++j) {
      if (j < i && g[j] == i) {
        passesleft = 1;
      } else if (j > i && g[j] == i) {
        passesright = 1;
      }
    }
    if ((!passesright && passesleft && g[i] == i-1) || (!passesleft && passesright && g[i] == i+1)) {
      covered[g[i]] = 1;
      ++pos;
    }
  }

  cout << pos << "\n";

  return 0;
}
