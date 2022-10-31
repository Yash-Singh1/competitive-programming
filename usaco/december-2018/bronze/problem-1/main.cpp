#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);

  pair<int,int> p[3];
  for (int i{0}; i < 3; ++i) {
    cin >> p[i].first >> p[i].second;
  }

  int bef;
  for (int i{0}; i < 100; ++i) {
    bef = p[((i % 3) + 1) % 3].second;
    p[((i % 3) + 1) % 3].second = min(p[((i % 3) + 1) % 3].first, p[(i % 3)].second + p[((i % 3) + 1) % 3].second);
    p[(i % 3)].second -= p[((i % 3) + 1) % 3].second - bef;
  }

  cout << p[0].second << "\n" << p[1].second << "\n" << p[2].second << "\n";

  return 0;
}
