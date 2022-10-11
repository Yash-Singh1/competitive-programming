#include <bits/stdc++.h>

using namespace std;

int main() {
  ofstream fout("cowsignal.out");
  ifstream fin("cowsignal.in");
  int m, n, k;
  fin >> m >> n >> k;
  while (m--) {
    string s;
    fin >> s;
    for (int j{0}; j < k; ++j) {
      for (int i{0}; i < n; ++i) {
        for (int l{0}; l < k; ++l) {
          fout << s[i];
        }
      }
      fout << "\n";
    }
  }
}
