#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; 
  cin >> n;
  
  vector<int> a(n);
  for (int i{0}; i < n; ++i) cin >> a[i];

  stack<pair<int,int>> s;
  for (int i{0}; i < n; ++i) {
    while (s.size() && s.top().first >= a[i]) {
      s.pop();
    }
    if (s.size()) {
      cout << s.top().second + 1;
    } else {
      cout << 0;
    }
    if (i != n - 1) {
      cout << " ";
    }
    s.push({a[i], i});
  }

  cout << "\n";

  return 0;
}
