// Time limit exceeded, still figuring out why

#include <bits/stdc++.h>

using namespace std;

int parents[100005];
int sz[100005];

int parent(int i) {
    if (parents[i] != i) {
        parents[i] = parent(parents[i]);
        return parents[i];
    }
    return i;
}

void merge(int x, int y) {
    x = parent(x);
    y = parent(y);
    if (x == y) {
        return;
    }
    if (x > y) {
        parents[y] = x;
        sz[x] += sz[y];
    } else {
        parents[x] = y;
        sz[y] += sz[x];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i{1}; i <= n; ++i) {
        parents[i] = i;
        sz[i] = 1;
    }
    for (int i{1}; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
        unordered_set<int> p;
        int mx{-1};
        for (int j{1}; j <= n; ++j) {
            p.insert(parent(j));
            if (sz[parent(j)] > mx) {
                mx = sz[parent(j)];
            }
        }
        cout << p.size() << " " << mx << "\n";
    }
}
