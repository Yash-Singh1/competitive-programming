#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t;

  vector<bool> fibb(100001);
  fibb[0] = 1;
  fibb[1] = 1;
  int fib1 = 1, fib2 = 1;
  while (true) {
    if (fib1 + fib2 <= 100000) {
      swap(fib1, fib2);
      fib2 = fib1 + fib2;
      fibb[fib2] = 1;
    } else {
      break;
    }
  }

  for (int j{0}; j < 5; ++j) {
    for (int i{0}; i < (int)fibb.size(); ++i) {
      int div{10};
      while (div <= n) {
        if (fibb[i % div] && fibb[(i - (i % div)) / div]) {
          fibb[i] = 1;
        }
        div *= 10;
      }
    }
  }

  while (t--) {
    cin >> n;
    int div{10};
    while (div <= n) {
      if (fibb[n % div] && fibb[(n - (n % div)) / div]) {
        cout << "YES\n";
        goto end;
      }
      div *= 10;
    }
    cout << "NO\n";
    end: continue;
  }

  return 0;
}
