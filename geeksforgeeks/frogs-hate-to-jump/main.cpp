#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin >> t;
	++t;
	while (--t) {
	    int n;
	    cin >> n;
	    int a[n];
	    for (int i{0}; i < n; ++i) {
	        cin >> a[i];
	    }
	    int b[n];
	    b[0] = 0;
	    for (int i{1}; i < n; ++i) {
	        b[i] = -1;
	    }
	    for (int i{0}; i < n; ++i) {
	        if (b[i] == -1) {
	            continue;
	        }
	        for (int j{i + 1}; j <= i + a[i]; ++j) {
	            if (b[j] == -1 || b[i] + 1 < b[j]) {
	                b[j] = b[i] + 1;
	            }
	        }
	    }
	    cout << b[n - 1] << "\n";
	}
	return 0;
}
