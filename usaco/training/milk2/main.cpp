/*
ID: saiansh1
LANG: C++
TASK: milk2
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("milk2.out");
  ifstream fin("milk2.in");

  int n;
  fin >> n;

  vector<pair<int, int>> v(n);
  for (auto &e: v) {
    int x, y;
    fin >> x >> y;
    e = {x, y};
  }
  sort(v.begin(), v.end());
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < i; ++j) {
      if (v[j].first == -1) {
        continue;
      }
      if (v[i].first > v[j].first) {
        if (v[j].second >= v[i].first) {
          v[i] = {v[j].first, max(v[j].second, v[i].second)};
          v[j] = {-1, -1};
        }
      } else {
        v[i].second = max(v[i].second, v[j].second);
        v[j] = {-1, -1};
      }
    }
  }
  int mx{-1};
  for (const auto &e: v) {
    if (e.first == -1) {
      continue;
    }
    int minusit{e.second - e.first};
    if (minusit > mx) {
      mx = minusit;
    }
  }
  fout << mx;
  sort(v.begin(), v.end(), [](auto &left, auto &right) {
    return left.second < right.second;
  });
  mx = -1;
  for (int i{1}; i < n; ++i) {
    if (v[i - 1].first == -1) {
      continue;
    }
    int mit{v[i].first - v[i - 1].second};
    if (mit > mx) {
      mx = mit;
    }
  }
  fout << " " << max(mx, 0) << "\n";
}
