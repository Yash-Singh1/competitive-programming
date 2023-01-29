#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  
  vector<bool> coprime(n);
  ll p{1};
  int c{0};
  for (int i{1}; i < n; ++i) {
    if (gcd(i, n) == 1) {
      coprime[i] = 1;
      p *= i;
      p %= n;
      ++c;
    }
  }

  if (p != 1) {
    coprime[p] = 0;
    --c;
  }

  cout << c << "\n";
  for (int i{1}; i < n; ++i) {
    if (coprime[i]) cout << i << " ";
  }
  cout << "\n";

  return 0;
}
