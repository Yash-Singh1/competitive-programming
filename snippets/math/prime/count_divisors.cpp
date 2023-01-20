int divisors{0};
for (int i{0}; i * i <= n; ++i) {
  if (n % i == 0) {
    divisors += (i * i == n) ? 1 : 2;
  }
}
