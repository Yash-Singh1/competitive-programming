#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    int ot{t};
    while (t--) {
        int n, k;
        cin >> n >> k;
        int lst{-1};
        int lstc{0};
        int cdowns{0};
        while (n--) {
            int x;
            cin >> x;
            if (x == k) {
                lstc = 1;
            }
            if (lst - 1 == x && x != k) {
                ++lstc;
            } else if (x != k) {
                lstc = 0;
            }
            if (x == 1 && lstc >= k) {
                lstc = 0;
                ++cdowns;
            }
            lst = x;
        }
        cout << "Case #" << (ot-t) << ": " << cdowns << "\n";
    }
}
