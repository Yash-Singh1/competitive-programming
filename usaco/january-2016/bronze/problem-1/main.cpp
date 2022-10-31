#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);

  int n;
  cin >> n;

  pair<char,int>p[n];
  for (int i{0};i<n; ++i) {
    cin >> p[i].first >> p[i].second;
  }

  pair<int,int> loc{0,0};
  int grid[2001][2001];
  for (int i{0}; i < 2001; ++i) {
    for (int j{0}; j < 2001; ++j) {
      grid[i][j] = -1;
    }
  }
  grid[1000][1000] = 0;
  int t{0};
  int mn{INT_MAX};
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < p[i].second; ++j) {
      if (p[i].first == 'N') {
        ++loc.second;
      } else if (p[i].first == 'S') {
        --loc.second;
      } else if (p[i].first == 'E') {
        ++loc.first;
      } else {
        --loc.first;
      }
      ++t;
      if (grid[loc.first + 1000][loc.second + 1000] != -1) {
        // cout << loc.first  << " " << loc.second << " " << grid[loc.first + 1000][loc.second + 1000] << "\n";
        mn = min(mn, t - grid[loc.first + 1000][loc.second + 1000]);
      }
      grid[loc.first + 1000][loc.second + 1000] = t;
    }
  }

  cout << (mn==INT_MAX?-1:mn) << "\n";

  return 0;
}
