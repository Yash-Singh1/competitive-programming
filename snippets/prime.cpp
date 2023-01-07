vector<bool> composite(MAX_N + 1);
composite[0] = 1;
composite[1] = 1;

for (int i{2}; i * i <= MAX_N; ++i) {
  if (composite[i]) continue;
  for (int j{i*i}; j <= MAX_N; j += i) {
    composite[j] = 1;
  }
}
