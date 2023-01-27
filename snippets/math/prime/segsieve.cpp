const int H = 1e9;
const int L = 1e8;

int sq{sqrt(H)};
vector<bool> composite(sq + 1);
composite[0] = 1;
composite[1] = 1;

vector<int> primes;
for (int i{2}; i * i <= sq; ++i) {
  if (composite[i]) continue;
  primes.push_back(i);
  for (int j{i*i}; j <= sq; j += i) {
    composite[j] = 1;
  }
}

vector<int> composite_seg(h - l + 1, 0);
for (auto &prime: primes) {
  int low{(L / prime) * prime};
  if (low < L) low += prime;
  for (int i{low}; i <= H; i += prime) {
    composite_seg[i - L] = 1;
  }
}
