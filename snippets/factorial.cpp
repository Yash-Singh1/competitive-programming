// Calculating factorial in one go and memoizing it is much more reasonable than having a function calculate it lazily

vector<int> facts(MAX_N, -1);
facts[0] = 1;

for (int i{1}; i <= MAX_N; ++i) {
  facts[i] = (facts[i - 1] * i) % MOD;
}
