#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin >>t;++t;
	while (--t) {
	    int n;
	    cin >> n;
	    long long a[n];
	    for (int i{0}; i < n; ++i) {
	        cin >> a[i];
	    }
	    long long p[n], s[n];
	    p[0] = a[0];
	    for (int i{1}; i < n; ++i) {
	        p[i] = p[i - 1]+ a[i];
	    }
	    s[n - 1] = a[n - 1];
	    for (int i{n - 2}; i >= 0; --i) {
	        s[i] = s[i + 1] + a[i];
	    }
	    int done = 0;
	    for (int i{0}; i < n; ++i) {
	        if (p[i] == s[i]) {
	            cout << i + 1 << endl;
	            done = 1;
	            break;
	        }
	    }
	    if (done == 0) cout << -1 << endl;
	}
	return 0;
}
