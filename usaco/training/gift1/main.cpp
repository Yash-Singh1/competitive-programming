/*
ID: saiansh1
LANG: C++
TASK: gift1
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("gift1.out");
  ifstream fin("gift1.in");
  int n;
  fin >> n;
  map<string, int> a;
  string ar[n];
  for (int i{0}; i < n; ++i) {
    string x;
    fin >> x;
    a[x] = 0;
    ar[i] = x;
  }
  for (int i{0}; i < n; ++i) {
    string x;
    fin >> x;
    int k, l;
    fin >> k >> l;
    int d{l == 0 ? 0 : k / l};
    for (int i{0}; i < l; ++i) {
      string y;
      fin >> y;
      a[y] += d;
    }
    a[x] -= d * l;
  }
  for (int i{0}; i < n; ++i) {
    fout << ar[i] << " " << a[ar[i]] << "\n";
  }
}
