/*
ID: saiansh1
LANG: C++
TASK: holstein
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("holstein.in", "r", stdin);
  freopen("holstein.out", "w", stdout);

  int v, g;
  cin >> v;
  int req[v];
  for (int i{0}; i < v; ++i) {
    cin >> req[i];
  }
  cin >> g;
  int feeds[g][v];
  for (int i{0}; i < g; ++i) {
    for (int j{0}; j < v; ++j) {
      cin >> feeds[i][j];
    }
  }
  int ans{INT_MAX};
  int ansi{0};
  int fed[v];
  for (int i{0}; i < (1<<g); ++i) {
    int tot{0};
    for (int j{0}; j < v; ++j) fed[j] = 0;
    for (int j{0}; j < g; ++j) {
      if (i&(1<<j)) {
        ++tot;
        for (int k{0}; k < v; ++k) {
          fed[k] += feeds[j][k];
        }
      }
    }
    bool works{1};
    for (int j{0}; j < v; ++j) {
      if (fed[j] < req[j]) {
        works = 0;
        break;
      }
    }
    if (works) {
      if (tot < ans) {
        ans = tot;
        ansi = i;
      }
    }
  }

  cout << ans;
  for (int i{0}; i < g; ++i) {
    if (ansi&(1<<i)) {
      cout << " " << i+1;
    }
  }
  cout << "\n";
}
