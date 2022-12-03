/*
ID: saiansh1
LANG: C++
TASK: combo
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("combo.in", "r", stdin);
  freopen("combo.out", "w", stdout);

  int n;
  cin >> n;

  set<pair<int,pair<int,int>>>s;
  int a, b, c;
  for (int i{0}; i < 2; ++i) {
    cin >> a >> b >> c;
    for (int j{a-2}; j <= a+2; ++j) {
      for (int k{b-2}; k <= b+2; ++k) {
        for (int l{c-2}; l <= c+2; ++l) {
          pair<int,pair<int,int>> r{j, {k, l}};
          if (j >= n*2) continue;
          if (j < 1) {
            r.first = n + j;
            if (r.first < 1) continue;
          } else if (j > n) {
            r.first = j % n;
          }
          if (k >= n*2) continue;
          if (k < 1) {
            r.second.first = n + k;
            if (r.second.first < 1) continue;
          } else if (k > n) {
            r.second.first = k % n;
          }
          if (l >= n*2) continue;
          if (l < 1) {
            r.second.second = n + l;
            if (r.second.second < 1) continue;
          } else if (l > n) {
            r.second.second = l % n;
          }
          s.insert(r);
        }
      }
    }
  }

  // for (auto it = s.begin(); it != s.end(); it = next(it)) {
  //   cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
  // }

  cout << s.size() << "\n";
}
