#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  long long t;
  cin >> t;
  long long ot{t};
  while (t--) {
    long long n, q;
    cin >> n >> q;
    long long a[n];
    long long b[n];
    long long orz[n];
    for (long long i{0}; i < n; ++i) {
      cin >> a[i];
      orz[i] = a[i];
      if (i % 2 == 1) {
        a[i] *= -1;
      }
      b[i] = a[i] * (i + 1);
      if (i != 0) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
      }
    }
    long long totq{0};
    while (q--) {
      char o;
      long long x, y;
      cin >> o >> x >> y;
      if (o == 'Q') {
        long long val{b[y - 1]};
        if (x != 1) {
          val -= b[x - 2];
        }
        val -= (a[y - 1] - (x != 1 ? a[x - 2] : 0)) * (x - 1);
        if (x % 2 == 0) {
            val *= -1;
        }
        totq += val;
      } else {
        orz[x - 1] = y;
        a[0] = orz[0];
        b[0] = orz[0];
        for (long long i{1}; i < n; ++i) {
          a[i] = orz[i];
          if (i % 2 == 1) {
            a[i] *= -1;
          }
          b[i] = a[i] * (i + 1);
          a[i] += a[i - 1];
          b[i] += b[i - 1];
        }
      }
    }
    cout << "Case #" << (ot - t) << ": " << totq << "\n";
  }
}
