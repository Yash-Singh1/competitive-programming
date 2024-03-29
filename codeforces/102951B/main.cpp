#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  sort(a,a+n);

  int tot{0}, sm{0};
  while (sm < x && tot < n) {
    sm += a[tot++];
  }

  if (sm > x) {
    --tot;
  }

  cout << tot << "\n";

  return 0;
}
