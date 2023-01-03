// Checking how many times each number from 1...2000 divides into 2000 summed up

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int ans{0};
  for (int i{1}; i <= 2000; ++i) {
    ans += 2000 / i;
  }
  cout << ans << "\n";

  return 0;
}
