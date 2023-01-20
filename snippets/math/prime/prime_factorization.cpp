// Brought from USACO Guide Prime Factorization solution to Counting Divisors - CSES

for (int i = 2; i <= MAX_N; i++) {
  if (max_div[i] == 0) {
    for (int j = i; j <= MAX_N; j += i) {
      max_div[j] = i;
    }
  }
}

int x;
cin >> x;
int div_num = 1;
while (x != 1) {
  int prime = max_div[x];
  int count = 0;
  while (x % prime == 0) {
    count++;
    x /= prime;
  }
  div_num *= count + 1;
}
cout << div_num << '\n';
