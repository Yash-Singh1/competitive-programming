#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    ++t;
    while (--t)
    {
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;

        if ((sx - 2 < d && sy - 2 < d) || (sx + d >= n && sy + d >= m))
        {
            cout << -1 << endl;
            continue;
        }

        cout << n + m - 2 << endl;
    }
    return 0;
}
