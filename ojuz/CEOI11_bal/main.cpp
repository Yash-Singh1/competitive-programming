#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<int,ld> pld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(10);
  int n;
  cin >> n;

  stack<pld> s;

  int x;
  ld r;
  vector<ld> ans(n);
  for (int i{0}; i < n; ++i) {
    cin >> x >> r;
    while (s.size()) {
      pld tp = s.top();
      r = min(r, (ld)pow(tp.first - x, 2.0L) / (4.0L * tp.second));
      if (r >= tp.second) {
        s.pop();
      } else {
        break;
      }
    }
    ans[i] = r;
    s.push({x, r});
  }

  for (auto &rad: ans) {
    cout << rad << "\n";
  }

  return 0;
}
