#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;

  long long div{0};
  long long sm{0};

  map<long long, long long> m;
  m[0] = 1;

  for (long long i{0}; i < n; ++i) {
    long long x;
    cin >> x;
    sm = ((sm + x) % n + n) % n;
    if (m.find(sm) != m.end()) {
      div += m[sm];
      ++m[sm];
    } else {
      m[sm] = 1;
    }
  }

  cout << div;

  return 0;
}
