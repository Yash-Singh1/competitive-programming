// Some weird edge case WA, 0% accuracy so not trying

#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin >> t;
	++t;
	while (--t) {
	    int n, q;
	    cin >> n >> q;
	    int a[n];
	    cin >> a[0];
	    for (int i{1}; i < n; ++i) {
	        int x;
	        cin >> x;
	        a[i] = a[i - 1] + x;
	    }
	   // for (int i{0}; i < n; ++i) {
	   //     cout << a[i] << " ";
	   // }
	   // cout << endl;
	    for (int i{0}; i < q; ++i) {
	        int x, y;
	        cin >> x >> y;
            while (y > x && a[y] < a[y - 1]) {
                --y;
            }
	        if (x == 0) {
	            cout << a[y] << " ";
	        } else {
	            cout << a[y] - a[x - 1] << " ";
	        }
	    }
	    cout << endl;
	}
	return 0;
}
