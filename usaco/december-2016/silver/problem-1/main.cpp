#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);

  int n, q;
  cin >> n >> q;

  vector<int> haybales(n);
  for (int i{0}; i < n; ++i) {
    cin >> haybales[i];
  }
  sort(haybales.begin(), haybales.end());

  int left, right;
  while (q--) {
    cin >> left >> right;
    int l{0}, r{n-1}, leftpos{-1};
    while (l <= r) {
      int mid{(l+r)/2};
      if (haybales[mid] == left) {
        leftpos = mid;
        break;
      } else if (haybales[mid] > left) {
        if (haybales[mid] <= right) leftpos = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    l = 0;
    r = n-1;
    int rightpos{-1};
    while (l <= r) {
      int mid{(l+r)/2};
      if (haybales[mid] == right) {
        rightpos = mid;
        break;
      } else if (haybales[mid] < right) {
        if (haybales[mid] >= left) rightpos = mid;
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    if (rightpos == -1) {
      cout << 0 << "\n";
    } else {
      cout << (rightpos - leftpos + 1) << "\n";
    }
  }

  return 0;
}
