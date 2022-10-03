/*
ID: saiansh1
LANG: C++
TASK: milk
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("milk.out");
  ifstream fin("milk.in");
  
  int n, m;
  fin >> n >> m;
  vector<pair<int, int>> v;
  for (int i{0}; i < m; ++i) {
    int a, b;
    fin >> a >> b;
    v.push_back({a,b});
  }
  sort(v.begin(), v.end());
  int cost{0};
  for (auto p: v) {
    if (n == 0) break;
    int mu{min(p.second, n)};
    n -= mu;
    cost += mu * p.first;
  }
  fout << cost << "\n";
}
