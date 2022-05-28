#include<iostream>
#include <ios>
#include <map>
#define endl "\n"

using namespace std;

using std::cin;

int main()
 {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    ++t;
    while (--t) {
        int n, m;
        cin >> n >> m;
        int a[n];
        map<int, int> map;
        for (int i{0}; i < n; ++i) {
            cin >> a[i];
        }
        for (int i{0}; i<m; ++i) {
            int in;
            cin >> in;
            map[in] = 1;
        }
        for (int i{0}; i < n; ++i) {
            if (map[a[i]] != 1) {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
    
     return 0;
 }
