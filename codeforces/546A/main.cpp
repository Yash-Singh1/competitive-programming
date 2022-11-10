#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, n, w;
  cin >> k >> n >> w;

  int cost{((w)*(w+1))/2*k};
  cout << cost - min(n, cost) << "\n";

  return 0;
}
