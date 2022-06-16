#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  int score {-1};
  for (int i{0}; i < n; ++i) {
    int x;
    cin >> x;
    if (x <= 0 || x < score) {
      cout << i;
      return 0;
    } else if (i == k - 1) {
      score = x;
    }
  }
  cout << n;
}
