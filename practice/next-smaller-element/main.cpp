#include <bits/stdc++.h>

using namespace std;

int main() {
        int n;
        cin >> n;
        vector<long long> arr;
        for (int i{0}; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
            stack<long long>s;
        vector<long long> r(n, -1);
        for (int i{0}; i < n; ++i) {
            long long e{arr[i]};
            if (s.empty() || arr[s.top()] <= e) {
                s.push(i);
            } else {
                while (!s.empty() && arr[s.top()] > e) {
                    r[s.top()] = e;
                    s.pop();
                }
                s.push(i);
            }
        }
        for (auto e: r) {
            cout << e << " ";
        }
        return 0;
}
