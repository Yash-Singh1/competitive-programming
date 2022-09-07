#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  long long n;
  cin >> n;

  long long total[n + 5];
  for (long long i{0}; i <= n; ++i) {
    total[i] = 0;
  }
  for (long long i{1}; i <= n / 2; ++i) {
    for (long long j{i}; j <= n; j += i) {
      ++total[j];
    }
  }
  long long mx{-1};
  for (long long i{0}; i <= n; ++i) {
    mx = max(mx, total[i]);
  }
  cout << mx + 1;
  return 0;
}
