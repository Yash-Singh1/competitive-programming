// n = length of string
// MOD = prime modulus
// We can use modular multiplication here if required
// 26 can be replaced with the range of characters
// Remember the binpow function for dividing the factor when using the prefix sum
// You can also randomly generate the base of the polynomial hash for open hacking contests

ll hash[n];
ll terms[n];
ll cur{0};
ll term{1};

for (int i{0}; i < n; ++i) {
  cur += (term * (s[i] - 'a')) % MOD;
  cur %= MOD;
  hash[i] = cur;
  terms[i] = term;
  term *= 26LL;
  term %= MOD;
}

terms[n - 1] = binpow(terms[n - 1], MOD - 2, MOD);
for (int i{n - 1}; i >= 0; --i) {
  terms[i - 1] = terms[i] * 26LL % MOD;
}

void queryHash(int i, int j) {
  return ((hash[j] - (i == 0 ? 0 : hash[i - 1])) * terms[i]) % MOD;
}
