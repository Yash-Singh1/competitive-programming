#include <bits/stdc++.h>

using namespace std;

// Linear sieve template from cf

#define  MAXN 10000000
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

  int n;
  cin >> n;

  sieve(MAXN);

  for (int i{n+1}; i <= MAXN; ++i) {
    if (!is_composite[i]) {
      cout << i << '\n'; return 0;
    }
  }

  return 0;
}
