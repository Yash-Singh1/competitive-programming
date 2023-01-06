#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i{0}; i < n; ++i) cin >> a[i];
    int lone{0};
    for (int i{0}; i < n; ++i) {
      if (a[i] == lone + 1) {
        lone = a[i];
      }
    }
    cout << (int)ceil((double)(n-lone)/k) << "\n";
  }

  return 0;
}
