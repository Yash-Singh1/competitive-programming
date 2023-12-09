#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  vector<pair<int,int>> interval(n, {-1, -1});
  for (int i{0}; i < n; ++i) {
    if (a[i]) {
      if (interval[a[i]-1].first == -1) {
        interval[a[i]-1].first = i;
      }
      interval[a[i]-1].second = i;
    }
  }

  stack<int> s;
  int mx{0};
  for (int i{0}; i < n; ++i) {
    if (a[i]) {
      if (i == interval[a[i]-1].first) {
        s.push(a[i]-1);
      }
      mx = max(mx, (int)s.size());
      if (i == interval[a[i]-1].second) {
        if (s.top() == a[i]-1) {
          s.pop();
        } else {
          cout << "-1\n";
          return 0;
        }
      } else if (i != interval[a[i]-1].first) {
        if (s.top() != a[i]-1) {
          cout << "-1\n";
          return 0;
        }
      }
    }
  }

  cout << mx << '\n';

  return 0;
}
