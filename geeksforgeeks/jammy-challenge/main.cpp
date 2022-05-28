#include<iostream>
#include <ios>
#include <algorithm>
#define endl "\n"

using namespace std;

using std::cin;

int main()
 {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    ++t;
    while (--t) {
	int m, n;
	cin >> m >> n;
	int gcd{1};
	for (int i{std::min(m, n)}; i >= 2; --i) {
	    if (m % i == 0 && n % i == 0) {
	        gcd = i;
	        break;
	    }
	}
	long long fib1{0};
	long long fib2{1};
	for (int i{2}; i <= gcd; ++i) {
	    long long ans {fib1 + fib2};
	    fib1 = fib2;
	    fib2 = ans;
	    fib1 %= 100;
	    fib2 %= 100;
	}
	string ans{std::to_string(fib2)};
	if (ans.length() > 2) {
	    string ans2 {ans.substr(ans.length() - 2)};
	    if (ans2.rfind("0", 0) == 0) {
	        cout << ans.substr(ans.length() - 1) << endl;
	    }
	    else
	        cout << ans.substr(ans.length() - 2) << endl;
	} else {
	    cout << ans << endl;
	}
    }
	
	return 0;
}
