// WIP: Some sort of edge case Runtime Error, but main idea is down
// Could have some simplicity by extracting ternaries into variables

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
    if (n == 1) {
        cout << (a[0] + k);
        return 0;
    }
    bool odd{(n & 1) == 1};
    ++k;
    while (--k) {
        a[n / 2]++;
        if (n > 1 && a[odd ? (n / 2) : (n / 2 - 1)] > a[(odd ? (n / 2) : (n / 2 - 1)) + 1]) {
            long long c{a[n / 2]};
            auto ub{upper_bound(a.begin(), a.end(), a[(odd ? (n / 2) : (n / 2 - 1)) + 1])};
            if (ub == a.end()) {
                a[odd ? (n / 2) : (n / 2 - 1)] = a[n - 1];
                a[n - 1] = c;
            } else {
                a[odd ? (n / 2) : (n / 2 - 1)] = a[ub - a.begin() - 1];
                a[ub - a.begin() - 1] = c;
            }
        }
    }
    if (odd) {
        cout << a[n / 2];
    } else {
        cout << (a[(n / 2) - 1] + a[(n / 2)]) / 2;
    }
    return 0;
}
