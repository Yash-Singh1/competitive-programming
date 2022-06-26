#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  int k;
  cin >> n >> k;
  map<int, int> m;
  int ans{0};
  for (int i{0}; i < n; ++i) {
    int x;
    cin >> x;
    if (m[x - k]) {
        ans += m[x- k ];
    }
    if (m[x + k] ) {
        ans  += m[x + k];
    }
    m[x]++;
  }
  cout << ans;
}
