#include <bits/stdc++.h>

using namespace std;

struct Node {
	int x1, x2, y1, y2, dir;
};

vector<vector<vector<vector<vector<int>>>>> dist(20, vector<vector<vector<vector<int>>>>(20, vector<vector<vector<int>>>(20, vector<vector<int>>(20, vector<int>(4, INT_MAX)))));

int getstate(Node state) {
	return dist[state.x1][state.y1][state.x2][state.y2][state.dir];
}

void setstate(Node state, int d) {
	dist[state.x1][state.y1][state.x2][state.y2][state.dir] = d;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

	freopen("cownav.in", "r", stdin);
  freopen("cownav.out", "w", stdout);

  int n;
	cin >> n;
	vector<vector<char>> grid(n,vector<char>(n));
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < n; ++j) {
			cin >> grid[i][j];
		}
	}

	queue<Node> q;
	Node start;
	start.x1 = n-1;
	start.x2 = n-1;
	start.y1 = 0;
	start.y2 = 0;
	start.dir = 0;
	q.push(start);

	int dx[4] {-1, 0, 1, 0};
	int dy[4] {0, 1, 0, -1};
	setstate(start, 0);
	while (q.size()) {
		Node u = q.front();
		q.pop();
		// cout << '(' << u.x1 << ", " << u.y1 << "), (" << u.x2 << ", " << u.y2 << ") " << u.dir << "\n";
		Node other = u;
		other.dir += 1;
		other.dir %= 4;
		if (getstate(other) == INT_MAX) {
			setstate(other, getstate(u) + 1);
			q.push(other);
		}
		other = u;
		other.dir += 3;
		other.dir %= 4;
		if (getstate(other) == INT_MAX) {
			setstate(other, getstate(u) + 1);
			q.push(other);
		}
		other = u;
		if ((u.x1 != 0 || u.y1 != n-1) && !(u.x1 + dx[u.dir] < 0 || u.x1 + dx[u.dir] >= n || u.y1 + dy[u.dir] < 0 || u.y1 + dy[u.dir] >= n) && grid[u.x1 + dx[u.dir]][u.y1 + dy[u.dir]] != 'H') {
			other.x1 += dx[u.dir];
			other.y1 += dy[u.dir];
		}
		if ((u.x2 != 0 || u.y2 != n-1) && !(u.x2 + dx[(u.dir+1)%4] < 0 || u.x2 + dx[(u.dir+1)%4] >= n || u.y2 + dy[(u.dir+1)%4] < 0 || u.y2 + dy[(u.dir+1)%4] >= n) && grid[u.x2 + dx[(u.dir+1)%4]][u.y2 + dy[(u.dir+1)%4]] != 'H') {
			other.x2 += dx[(u.dir+1)%4];
			other.y2 += dy[(u.dir+1)%4];
		}
		if (u.x1 == 0 && u.y1 == n-1 && u.x2 == 0 && u.y2 == n-1) {
			cout << getstate(u) << '\n';
			return 0;
		}
		if (getstate(other) == INT_MAX) {
			setstate(other, getstate(u) + 1);
			q.push(other);
		}
	}

	cout << -1 << '\n';

  return 0;
}
