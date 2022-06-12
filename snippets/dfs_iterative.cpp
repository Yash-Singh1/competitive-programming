// Depth-First Search

#include <bits/stdc++.h>

using namespace std;

const int n = 100;
vector<int> a[n];
bool visited[n];

int dfs(int start) {
    int tot{0};
    stack<int> s;
    s.push(start);
    while (!s.empty()) {
        int now{s.top()};
        ++tot;
        visited[now] = 1;
        s.pop();
        for (auto neighbor: a[now]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }
    return tot;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i{0}; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        visited[x] = 0;
    }
    cout << dfs(n);
}
