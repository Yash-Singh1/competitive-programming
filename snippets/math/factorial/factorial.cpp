// Calculating factorial in one go and memoizing it is much more reasonable than having a function calculate it lazily
// If calculating inverses too, make sure to use the binpow function

vector<ll> facts(MAX_N + 1, -1);
vector<ll> inv(MAX_N + 1, -1);
facts[0] = 1;

for (ll i{1}; i <= MAX_N; ++i) {
  facts[i] = (facts[i - 1] * i) % MOD;
}
inv[MAX_N] = binpow(facts[MAX_N], MOD - 2, MOD);
for (ll i{MAX_N}; i >= 1; --i) {
  inv[i - 1] = inv[i] * i % MOD;
}
