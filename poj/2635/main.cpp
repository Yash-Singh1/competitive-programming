#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)1e6;

vector<int> prime;
bool is_composite[MAXN+1];

void sieve (int n) {
  fill (is_composite, is_composite + n, false);
  for (int i = 2; i < n; ++i) {
    if (!is_composite[i]) prime.push_back (i);
    for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
      is_composite[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  sieve(MAXN+1);

  int k, l;
  while (true) {
    cin >> k >> l;
    if (k == 0 && l == 0) {
      return 0;
    }
    int fail{0};
    for (auto p: prime) {
      if (p >= l) break;
      if (k % p == 0) {
        fail = p;
        break;
      }
    }
    if (fail) {
      cout << "BAD " << fail << "\n";
    } else {
      cout << "GOOD\n";
    }
  }

  return 0;
}
