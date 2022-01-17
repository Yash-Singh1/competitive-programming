#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    map <string, int> m;
    int q;
    cin >> q;
    for (int i {0}; i < q; ++i) {
        int type;
        cin >> type;
        string x;
        cin >> x;
        switch (type) {
            case 1:
            {    int y;
                cin >> y;
                m.insert(make_pair(x, 0));
                m[x] += y;
                break;}
            case 2:
                m.erase(x);
                break;
            case 3:
                cout << (m.find(x) == m.end() ? 0 : m[x]) << endl;
                break;
        }
    }
    return 0;
}
