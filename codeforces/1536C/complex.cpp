#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
  int ans{0};
	for (int q = 0; q < n; q++) {
		int x{q+1};
		int div_num = 0;
		for (int i = 1; i * i <= x; i++) {
			if (x % i == 0) {
				div_num += i * i == x ? 1 : 2;
			}
		}
		ans += div_num;
	}
  cout << ans << "\n";
}
