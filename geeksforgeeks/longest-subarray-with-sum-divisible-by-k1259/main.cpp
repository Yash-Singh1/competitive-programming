// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    long long sum{0};
	    map<long long, long long> m;
	    m[0] = 0;
	    long long maxDist{0};
	    for (int i{0}; i < n; ++i) {
	        sum += arr[i];
	        long long current{((sum % k)+k)%k};
	        if (m.find(current) == m.end()) {
	            m[current] = i + 1;
	        } else if (i - m[current] + 1 > maxDist) {
	            maxDist = i - m[current] + 1;
	        }
	    }
	    return maxDist;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends
  