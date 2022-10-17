#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("censor.out");
  ifstream fin("censor.in");

  string a, b;
  fin >> a >> b;

  string c = "";

  for (unsigned long i{0}; i < a.size(); ++i) {
    c += a[i];
    if (c.size() > b.size()) {
      // use substr instead of rfind because rfind checks entire string
      if (c.substr(c.size() - b.size(), b.size()) == b) {
        c.erase(c.size() - b.size(), b.size());
      }
    }
  }

  fout << c << "\n";
}
