#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
	cin >> n >> s;

	vector<vector<char>> grid(n, vector<char>(n));
	
	pii start, end;
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < n; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 'M') start = {i,j};
			else if (grid[i][j] == 'D') end = {i,j};
		}
	}

	queue<pair<int,int>> q;
	vector<vector<int>> pollu(n, vector<int>(n, INT_MAX));
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < n; ++j) {
			if (grid[i][j] == 'H') {
				pollu[i][j] = 0;
				q.push({i, j});
			}
		}
	}

	// precompute distance to pollinate all regions
	int dx[4] {-1, 1, 0, 0};
	int dy[4] {0, 0, 1, -1};
	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i{0}; i < 4; ++i) {
			if (x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= n || grid[x + dx[i]][y + dy[i]] == 'T') {
				continue;
			}
			if (pollu[x][y] + 1 < pollu[x + dx[i]][y + dy[i]]) {
				pollu[x + dx[i]][y + dy[i]] = pollu[x][y] + 1;
				q.push({x + dx[i], y + dy[i]});
			}
		}
	}

	// for (int i{0}; i < n; ++i) {
	// 	for (int j{0}; j < n; ++j) {
	// 		if (pollu[i][j] == INT_MAX) {
	// 			cout << '-' << ' ';
	// 			continue;
	// 		}
	// 		cout << pollu[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }

	// we can tell by construction that any adjacent cell will have either +1 or -1, we want to move on +1 route
	// similarly we can tell that a movement of s cells is +[0,s]
	// we want to find a maximum min over all segments of size s
	// we can start by precomputing the distance to each cell from M

	vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

	// implement binary search with bfs
	// can't precompute distances, they are dependent on bee timings
	int l{0}, r{n*n}, ans{-1};
	while (l <= r) {
		int mid{(l+r)/2};
		q.push(start);
		for (int i{0}; i < n; ++i) {
			for (int j{0}; j < n; ++j) {
				dist[i][j] = INT_MAX;
			}
		}
		dist[start.first][start.second] = 0;
		while (q.size()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i{0}; i < 4; ++i) {
				if (x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= n) continue;
				if (grid[x + dx[i]][y + dy[i]] == 'T') continue;
				if (pollu[x][y]-mid > (dist[x][y])/s && dist[x][y] + 1 < dist[x + dx[i]][y + dy[i]]) {
					dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
					q.push({x + dx[i], y + dy[i]});
				}
			}
		}
		// cout << mid << '\n';
		// for (int i{0}; i < n; ++i) {
		// 	for (int j{0}; j < n; ++j) {
		// 		if (dist[i][j] == INT_MAX) {
		// 			cout << '-' << ' ';
		// 			continue;
		// 		}
		// 		cout << dist[i][j] << ' ';
		// 	}
		// 	cout << '\n';
		// }
		if (dist[end.first][end.second] == INT_MAX) {
			r = mid-1;
		} else {
			l = mid+1;
			ans = mid;
		}
	}

	cout << ans << "\n";

  return 0;
}
