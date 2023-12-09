#include <bits/stdc++.h>

using namespace std;

vector<int> val;

int sibbonacci(int n) {
  if (val[n] == -1) {
    val[n] = sibbonacci(n/2) + sibbonacci(n-1);
  }
  return val[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  val.resize(n+1);
  for (int i{0}; i <= n; ++i) {
    val[i] = -1;
  }
  val[0] = 1;
  val[1] = 1;

  cout << sibbonacci(n) << '\n';

  return 0;
}
