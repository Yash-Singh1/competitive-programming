#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("blist.in", "r", stdin);
  freopen("blist.out", "w", stdout);

  int n;
  cin >> n;

  pair<int,int>p[n*2];

  for (int i{0}; i < n; ++i) {
    cin >> p[i*2].first >> p[i*2+1].first;
    int b;
    cin >> b;
    p[i*2].second = b;
    p[i*2+1].second = -b;
  }

  sort(p,p+n*2);

  int mx{0}, cur{0};
  for (int i{0}; i < n * 2; ++i) {
    cur += p[i].second;
    mx = max(cur,mx);
  }

  cout << mx << "\n";

  return 0;
}
