#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
	cin >> n >> k;

	cout << (int)pow(k+1, n) - 1 << '\n';

  return 0;
}
