/*
ID: saiansh1
LANG: C++
TASK: pprime
*/

#include <bits/stdc++.h>

using namespace std;

int pals[779] {/* copied output from gen.cpp, don't want to include here for language detection purposes */};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("pprime.in", "r", stdin);
  freopen("pprime.out", "w", stdout);

  int a, b;
  cin >> a >> b;
  for (int i{0}; i < 779; ++i) {
    if (pals[i] >= a && pals[i] <= b) {
      cout << pals[i] << "\n";
    }
  }
}
