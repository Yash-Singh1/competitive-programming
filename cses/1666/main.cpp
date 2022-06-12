#include <bits/stdc++.h>

using namespace std;

vector<int> a[100001];
bool visited[100001];

int dfs(int start) {
    if (visited[start]) {
        return false;
    }
    stack<int> s;
    s.push(start);
    bool visitedNow[100000];
    while (!s.empty()) {
        int now{s.top()};
        if (!visited[now]) {
            visitedNow[now] = true;
        }
        visited[now] = 1;
        s.pop();
        for (auto neighbor: a[now]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
            } else {
                if (!visitedNow[neighbor]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i{0}; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        visited[x] = 0;
    }
    int tot{0};
    vector<int> g;
    for (int i{1}; i <= n; ++i) {
        if (dfs(i)) {
            ++tot;
            g.push_back(i);
        }
    }
    cout << (tot - 1) << "\n";
    for (int i{0}; i < tot - 1; ++i) {
        if (tot > i + 1) {
            cout << g[i] << " " << g[i + 1] << "\n";
        }
    }
}
