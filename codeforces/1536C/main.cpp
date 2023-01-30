#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  int n;
  while (t--) {
    cin >> n;

    unordered_map<ll,int> m;
    int ks{0}, ds{0};
    char x;
    for (int i{0}; i < n; ++i) {
      cin >> x;
      if (x == 'K') ++ks;
      else ++ds;
      ll hs{0};
      hs += ds / gcd(ds, ks);
      hs <<= 23;
      hs += ks / gcd(ds, ks);
      ++m[hs];
      cout << m[hs] << " ";
    }
    cout << "\n";
  }

  return 0;
}
