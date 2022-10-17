#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("shell.out");
  ifstream fin("shell.in");

  int n;
  fin >> n;
  int ar[3] {0, 0, 0};
  int m[3] {1, 2, 3};
  for (int i{0}; i < n; ++i) {
    int a, b, g;
    fin >> a >> b >> g;
    int s{m[a - 1]};
    m[a - 1] = m[b - 1];
    m[b - 1] = s;
    ++ar[m[g - 1] - 1];
  }
  fout << max(ar[0], max(ar[1], ar[2]));
}
