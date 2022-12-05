/*
ID: saiansh1
LANG: C++
TASK: milk3
*/

#include <bits/stdc++.h>

using namespace std;

int capa[3];
int milk[3];
int tot{0};
set<int> s;

void iter() {
  if (milk[0] == 0) s.insert(milk[2]);
  if (tot == 15) return;
  int x, y;
  ++tot;
  for (int i{0}; i < 3; ++i) {
    if (milk[i] != 0) {
      for (int j{0}; j < 3; ++j) {
        if (i != j && milk[j] != capa[j]) {
          x = milk[i];
          y = milk[j];
          milk[i] = max(0, milk[i] - (capa[j]-milk[j]));
          milk[j] = min(capa[j], milk[j] + x);
          iter();
          milk[i] = x;
          milk[j] = y;
        }
      }
    }
  }
  --tot;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("milk3.in", "r", stdin);
  freopen("milk3.out", "w", stdout);

  cin >> capa[0] >> capa[1] >> capa[2];
  milk[0] = 0; milk[1] = 0; milk[2] = capa[2];

  iter();

  for (auto it = s.begin(); it != s.end(); it = next(it)) {
    cout << *it << (it == prev(s.end()) ? "" : " ");
  }
  cout << "\n";
}
