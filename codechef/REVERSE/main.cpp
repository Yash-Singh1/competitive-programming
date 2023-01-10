#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main() {
	int n, m;
	cin >> n >> m;

	vector<pii> g[n];
	int x, y;
	for (int i{0}; i < m; ++i) {
	    cin >> x >> y;
	    --x; --y;
	    g[x].push_back({y, 0});
	    g[y].push_back({x, 1});
	}

    deque<int>q;
    q.push_front(0);
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    while (!q.empty()) {
        int qtop = q.front();
        q.pop_front();
        for (auto &ne: g[qtop]) {
            if (dist[qtop] + ne.second < dist[ne.first]) {
                dist[ne.first] = dist[qtop] + ne.second;
                if (ne.second == 1) {
                    q.push_back(ne.first);
                } else {
                    q.push_front(ne.first);
                }
            }
        }
    }
    
    if (dist[n - 1] == INT_MAX) cout << -1 << "\n";
    else cout << dist[n - 1] << "\n";

	return 0;
}
