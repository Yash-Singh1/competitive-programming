#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, t {0}, m {0};
    cin >> n;
    vector<pair<int, int>> a;
    for (int i{0}; i < n; ++i) {
        int d, f;
        cin >> d >> f;
        pair<int, int> p {d, f};
        a.push_back(p);
    }
    sort(a.begin(), a.end());
    for (auto p: a) {
        t += p.first;
        m += p.second - t;
    }
    std::cout << m;
}
