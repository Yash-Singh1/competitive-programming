// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

int count_set_bits(int *arr, int n) {
    int total {0};
    for (int i {0}; i < n; ++i) {
        int el {arr[i]};
        while (el) {
            total += el & 1;
            el >>= 1;
        }
    }
    return total;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << count_set_bits(arr, n) << endl;
    }
}
  // } Driver Code Ends