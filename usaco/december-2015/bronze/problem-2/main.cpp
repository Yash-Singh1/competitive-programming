#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  int a[100], b[100];
  int aloc{0};
  for (int i{0}; i < n; ++i) {
    int l, s;
    cin >> l >> s;
    for (int j{aloc}; j < aloc+l;++j){
      a[j]=s;
    }
    aloc+=l;
  }

  int bloc{0};
  for (int i{0}; i < m; ++i) {
    int l, s;
    cin >> l >> s;
    for (int j{bloc}; j < bloc+l;++j){
      b[j]=s;
    }
    bloc+=l;
  }

  int over{0};
  for (int i{0}; i < 100; ++i) {
    over = max(over, b[i] - a[i]);
  }

  cout << over;

  return 0;
}
