#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int sm(int a, int b) {
  return a + b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("radio.in", "r", stdin);
  freopen("radio.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  map<char,pii> movement;
  movement['N'] = {0, 1};
  movement['S'] = {0, -1};
  movement['E'] = {1, 0};
  movement['W'] = {-1, 0};

  pii sf, sb;
  cin >> sf.first >> sf.second >> sb.first >> sb.second;

  vector<char> movef(n), moveb(m);
  for (int i{0}; i < n; ++i) cin >> movef[i];
  for (int i{0}; i < m; ++i) cin >> moveb[i];

  vector<pii> posef(n + 1), poseb(m + 1);
  posef[0] = sf; poseb[0] = sb;
  for (int i{0}; i < max(n, m); ++i) {
    if (i < n) posef[i + 1] = {posef[i].first + movement[movef[i]].first, posef[i].second + movement[movef[i]].second};
    if (i < m) poseb[i + 1] = {poseb[i].first + movement[moveb[i]].first, poseb[i].second + movement[moveb[i]].second};
  }

  vector<vector<int>> order(n+1, vector<int>(m+1, INT_MAX));
  order[0][0] = 0;
  int ans{0};
  for (int i{0}; i <= n; ++i) {
    for (int j{0}; j <= m; ++j) {
      for (int k{1}; k < 4; ++k) {
        if (((k & 1) && i == n) && ((k & 2) && j == m)) continue;
        int np{(k & 1) && i != n}, mp{(k & 2) && j != m};
        order[i + np][j + mp] = min(order[i + np][j + mp], sm(order[i][j], pow(poseb[j + mp].first - posef[i + np].first, 2) + pow(poseb[j + mp].second - posef[i + np].second, 2)));
      }
    }
  }

  cout << order[n][m] << "\n";

  return 0;
}
