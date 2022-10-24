#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);

  int n;
  cin >> n;
  
  pair<int,int>p[n];
  for (int i{0};i<n;++i) {
    cin >> p[i].first >> p[i].second;
  }

  int a[1001];

  for (int i{0}; i < 1001; ++i) {
    a[i] = 0;
  }

  for (int i{0}; i < n; ++i) {
    for (int j{p[i].first}; j < p[i].second; ++j) {
      ++a[j];
    }
  }

  int mn{INT_MAX};
  for (int i{0}; i < n; ++i) {
    int val{0};
    for (int j{p[i].first}; j < p[i].second; ++j) {
      if (a[j]==1) {
        ++val;
      }
    }
    mn=min(val,mn);
  }

  int sm{0};
  for (int i{0}; i < 1001; ++i) {
    if (a[i]) {
      ++sm;
    }
  }

  cout << sm-mn;

  return 0;
}
