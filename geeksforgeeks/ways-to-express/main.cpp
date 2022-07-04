#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin >> t;
	++t;
	int pos[3] {1, 3, 4};
	while (--t) {
	    int n;
	    cin >> n;
	    long long dp[n + 1];
	    dp[0] = 1;
	    for (int i{1}; i <= n; ++i) {
	        dp[i] = 0;
	        for (int j{0}; j < 3; ++j) {
	            if (i - pos[j] >= 0) {
	                dp[i] += dp[i - pos[j]];
	                dp[i] %= 1000000007;
	            }
	        }
	    }
	   // for (int i{0}; i <= n; ++i) {
	   //     cout << dp[i] << " ";
	   // }
	   // cout << endl;
	    cout << dp[n] << endl;
	}
	return 0;
}
