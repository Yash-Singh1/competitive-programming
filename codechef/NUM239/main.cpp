#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	++t;
	while (--t) {
	    int l, r;
	    cin >> l >> r;
	    int lf, rf;
	    lf = (l - (l % 10)) / 10;
	    rf = (r - (r % 10)) / 10;
	    int ans = (rf - lf +1) * 3;
	    l %= 10;
	    r %= 10;
	    if (l > 2) {
	        --ans;
	    }
	    if (l > 3) {
	        --ans;
	    }
	    if (l > 9) {
	        --ans;
	    }
	    if (r < 9) {
	        --ans;
	    }
	    if (r < 3) {
	        --ans;
	    }
	    if (r < 2) {
	        --ans;
	    }
	    std::cout << ans << "\n";
	}
	return 0;
}
