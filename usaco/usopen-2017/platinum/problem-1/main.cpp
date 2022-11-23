#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("art.in", "r", stdin);
  freopen("art.out", "w", stdout);

  int n;
  cin >> n;

  int a[n][n];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  pair<pair<int,int>,pair<int,int>> dims[n*n];
  for (int i{0}; i < n*n; ++i) {
    dims[i] = {{-1, -1}, {-1, -1}};
  }
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (a[i][j] != 0) {
        if (dims[a[i][j] - 1].first.first == -1) {
          dims[a[i][j] - 1] = {{i, j}, {i, j}};
        }
        dims[a[i][j] - 1].first.first = min(dims[a[i][j] - 1].first.first, i);
        dims[a[i][j] - 1].first.second = min(dims[a[i][j] - 1].first.second, j);
        dims[a[i][j] - 1].second.first = max(dims[a[i][j] - 1].second.first, i);
        dims[a[i][j] - 1].second.second = max(dims[a[i][j] - 1].second.second, j);
      }
    }
  }

  // for (int i{0}; i < n * n; ++i) {
  //   cout << dims[i].first.first << " " << dims[i].first.second << " " << dims[i].second.first << " " << dims[i].second.second << "\n";
  // }
  // cout << "\n";

  int p[n][n];
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      p[i][j] = 0;
    }
  }

  for (int i{0}; i < n * n; ++i) {
    if (dims[i].first.first == -1) continue;
    ++p[dims[i].first.first][dims[i].first.second];
    if (dims[i].second.first != n - 1) {
      --p[dims[i].second.first + 1][dims[i].first.second];
    }
    if (dims[i].second.second != n - 1) {
      --p[dims[i].first.first][dims[i].second.second + 1];
    }
    if (dims[i].second.first != n - 1 && dims[i].second.second != n - 1) {
      ++p[dims[i].second.first + 1][dims[i].second.second + 1];
    }
  }

  // for (int i{0}; i < n; ++i) {
  //   for (int j{0}; j < n; ++j) {
  //     cout << p[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (i != 0) {
        p[i][j] += p[i - 1][j];
      }
      if (j != 0) {
        p[i][j] += p[i][j - 1];
      }
      if (i != 0 && j != 0) {
        p[i][j] -= p[i - 1][j - 1];
      }
    }
  }

  // for (int i{0}; i < n; ++i) {
  //   for (int j{0}; j < n; ++j) {
  //     cout << p[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  int starter[n * n];
  for (int i{0}; i < (n * n); ++i) {
    starter[i] = 1;
  }
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (p[i][j] > 1 && a[i][j] != 0) {
        starter[a[i][j] - 1] = 0;
      }
    }
  }

  int tot{0};
  for (int i{0}; i < (n * n); ++i) {
    if (starter[i]) {
      ++tot;
    }
  }

  bool allzero{1};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (a[i][j] != 0) allzero = 0;
    }
  }
  if (allzero) {
    cout << 0 << "\n";
    return 0;
  }

  cout << tot << "\n";

  return 0;
}
