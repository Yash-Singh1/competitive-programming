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
    map<int, int> m;
    int a[n];
    for (int i{0}; i < n; ++i) {
      cin >> a[i];
      ++m[a[i]];
    }
    vector<int> a2(n);
    int j{0};
    for (int i{0}; i < n; ++i) {
      if (m[a[i]] >= k) {
        a2[j++] = a[i];
        m[a[i]] = 0;
      }
    }
    sort(a2.begin(), a2.begin() + j);
    int lst{0};
    int inarow{0};
    int inarowstart{-1};
    int minarowstart{-1};
    int minarowend{-1};
    int minarow{0};
    for (int i{0}; i < j; ++i) {
      if (a2[i] == lst + 1) {
        ++inarow;
        if (inarow == 1) {
          inarowstart = a2[i];
        }
      } else {
        inarow = 1;
        inarowstart = a2[i];
      }
      if (inarow > minarow) {
        minarow = inarow;
        minarowstart = inarowstart;
        minarowend = a2[i];
      }
      lst = a2[i];
    }
    if (minarowstart == -1) {
      cout << -1 << "\n";
    } else {
      cout << minarowstart << " " << minarowend << "\n"; 
    }
  }

  return 0;
}
