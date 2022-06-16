#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b;
  double t;
  cin >> a >> b >> t;
  cout << floor((t + 0.5) / a) * b;
}
