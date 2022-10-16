#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;

  priority_queue<int> apps, aparts;
  for (int i{0}; i < n; ++i) {
    int x;
    cin >> x;
    apps.push(x);
  }
  for (int i{0}; i < m; ++i) {
    int x;
    cin >> x;
    aparts.push(x);
  }

  int cs{0};
  while (!apps.empty() && !aparts.empty()) {
    int nx{apps.top()};
    apps.pop();

    while (!aparts.empty() && !apps.empty() && (nx - aparts.top() > k || aparts.top() - nx > k)) {
      if (nx - aparts.top() > k) {
        while (!aparts.empty() && !apps.empty() && nx - aparts.top() > k) {
          nx = apps.top();
          apps.pop();
        }
      }
      else if (aparts.top() - nx > k) {
        while (!aparts.empty() && aparts.top() - nx > k) {
          aparts.pop();
        }
      }
    }

    if (!aparts.empty() && abs(nx - aparts.top()) <= k) {
      ++cs;
      aparts.pop();
    }
  }

  cout << cs;

  return 0;
}
