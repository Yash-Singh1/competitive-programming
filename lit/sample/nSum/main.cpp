#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int ans{0};
  ++n;
  while (--n) {
    int x;
    cin >> x;
    ans += x;
  }
  cout << ans;
}
