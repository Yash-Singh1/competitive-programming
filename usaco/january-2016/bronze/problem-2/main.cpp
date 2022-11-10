#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  int n;
  cin >> n;

  int a[n];
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }
  sort(a,a+n);

  int ans{1};
  for (int i{0}; i < n; ++i) {
    int rad{1};
    int destructed{1};
    int rstart{i}, lstart{i};
    bool rdo{1}, ldo{1};
    while (ldo || rdo) {
      int mxr{-1}, mxl{-1}, exr{0}, exl{0};
      // cout << i << " " << ldo << " " << rdo << " " << lstart << " " << rstart << " " << rad << " " << destructed << " " << "\n";
      if (ldo) {
        for (int j{lstart-1}; j >= 0; --j) {
          if (a[lstart] - a[j] > rad) {
            break;
          } else {
            mxl = j;
            ++exl;
          }
        }
      }
      if (rdo) {
        for (int j{rstart+1}; j < n; ++j) {
          if (a[j] - a[rstart] > rad) {
            break;
          } else {
            mxr = j;
            ++exr;
          }
        }
      }
      if (mxr == -1) {
        rdo = 0;
      } else {
        rstart = mxr;
        destructed += exr;
      }
      if (mxl == -1) {
        ldo = 0;
      } else {
        lstart = mxl;
        destructed += exl;
      }
      ++rad;
    }
    // cout << i << " " << destructed << " " << rad << "\n";
    ans = max(ans, destructed);
  }

  cout << ans << "\n";

  return 0;
}
