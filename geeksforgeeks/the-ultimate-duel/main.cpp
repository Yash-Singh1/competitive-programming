// { Driver Code Starts
// Initial Template for C++

#include "bits/stdc++.h"
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumAttacks(int X, int K) {
        int t;
        while (K >= 0) {
            K -= X;
            X += 2;
            ++t;
        }
        return t;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int X, K;
        cin >> X >> K;
        Solution ob;
        cout << ob.minimumAttacks(X, K) << "\n";
    }
}  // } Driver Code Ends