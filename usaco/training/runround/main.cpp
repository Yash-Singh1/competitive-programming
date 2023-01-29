/*
ID: saiansh1
LANG: C++
TASK: runround
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define LSOne(S) (S & -S)

ll m;
ll mn{LLONG_MAX};
int digits{INT_MAX};

void dfs(int mask, ll val) {
  if (__builtin_popcount(mask) > digits) return;
  bool runaround{1};
  int mask2;
  if (mask) {
    string vls{to_string(val)};
    mask2 = (1 << (vls[0] - '1'));
    int cur{vls[0] - '1'}, idx{0};
    while (true) {
      idx = (idx + cur + 1) % vls.size();
      cur = vls[idx] - '1';
      if (mask2 & (1<<cur)) {
        if ((1<<cur) != (1<<(vls[0] - '1'))) runaround = 0;
        break;
      } else {
        mask2 |= (1<<cur);
      }
    }
    runaround = runaround && (mask2 == mask);
  } else runaround = 0;
  if (runaround && val < mn && val > m) {
    mn = val;
    digits = __builtin_popcount(mask);
  }
  mask2 = ~mask;
  while (LSOne(mask2) <= (1<<8)) {
    dfs(mask + LSOne(mask2), val * 10 + __builtin_ctz(mask2) + 1);
    mask2 -= LSOne(mask2);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("runround.in", "r", stdin);
  freopen("runround.out", "w", stdout);

  cin >> m;

  dfs(0, 0);

  cout << mn << "\n";
}
