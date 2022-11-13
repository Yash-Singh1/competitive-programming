// WIP: Some sort of edge case Runtime Error, but main idea is down
// Could have some simplicity by extracting ternaries into variables
// UPDATE: Now has TLE and base test cases pass, still WIP on time complexity

#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, k;
    cin >> n >> k;
    vector<long long> a;
    for (int i{0}; i < n; ++i) {
        long long j;
        cin >> j;
        a.push_back(j);
    }
    sort(a.begin(), a.end());
    // for (int i{0}; i < n; ++i) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    if (n == 1) {
        cout << (a[0] + k);
        return 0;
    }
    // bool odd{(n & 1) == 1};
    ++k;
    long long mid{(n / 2)};
    while (--k) {
        a[n / 2]++;
        // for (int i{0}; i < n; ++i) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        if (a[mid] > a[(mid) + 1]) {
            long long c{a[n / 2]}; // switch storage
            auto ub{upper_bound(a.begin() + mid, a.end(), a[(mid) + 1])};
            //cout << a[(mid) + 1] << " " << ub - a.begin() << endl;
            if (ub == a.end()) {
                a[mid] = a[n - 1];
                a[n - 1] = c;
            } else {
                a[mid] = a[ub - a.begin() - 1];
                a[ub - a.begin() - 1] = c;
            }
            // for (int i{0}; i < n; ++i) {
            //     cout << a[i] << " ";
            // }
            // cout << endl;
        }
    }
    // if (odd) {
        cout << a[n / 2];
    // } else {
        // cout << (a[(n / 2) - 1] + a[(n / 2)]) / 2;
    // }
    return 0;
}
