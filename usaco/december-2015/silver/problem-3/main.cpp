#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("bcount.out");
  ifstream fin("bcount.in");

  int n, q;
  fin >> n >> q;

  int h[n], g[n], j[n];
  for (int i{0}; i < n; ++i) {
    h[i] = 0; g[i] = 0; j[i] = 0;
  }
  for (int i{0}; i < n; ++i) {
    int b;
    fin >> b;
    switch (b)
    {
    case 1:
      ++h[i];
      break;
    
    case 2:
      ++g[i];
      break;

    case 3:
      ++j[i];
      break;
    
    default:
      break;
    }
  }

  for (int i{1}; i < n; ++i) {
    h[i] += h[i - 1];
    g[i] += g[i - 1];
    j[i] += j[i - 1];
  }

  for (int i{0}; i < q; ++i) {
    int x, y;
    fin >> x >> y;
    fout << h[y - 1] - (x == 1 ? 0 : h[x - 2]) << " " << g[y - 1] - (x == 1 ? 0 : g[x - 2]) << " " << j[y - 1] - (x == 1 ? 0 : j[x - 2]) << "\n";
  }
}
