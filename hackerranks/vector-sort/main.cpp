#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n {0};
    cin >> n;
    vector<int> v;
    for (int i {0}; i < n; ++i) {
        int vi {0};
        cin >> vi;
        v.push_back(vi);
    }
    sort(v.begin(), v.end());
    for (auto vi: v) {
        cout << vi << ' ';
    }
    return 0;
}
