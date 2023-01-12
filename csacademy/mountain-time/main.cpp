// Many flaws but perfect example of sorting + DSU, and using doubly linked lists efficiently

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

// KACTL DSU Implementation

typedef vector<int> vi;
int N, M;
vector<vector<int>> grid(1000, vector<int>(1000));
vector<vector<int>> prominence(1000, vector<int> (1000, -1));

struct DSU {
	vi e;
	vi mx;
	vi mn;
	vector<list<pair<int,int>>> unknown;
	void init(int N, int M) { e = vi(N*M,-1); mn = vi(M*N); unknown = vector<list<pair<int,int>>>(N*M); mx = vi(N*M);
	   for (int i{0}; i < N; ++i) {
	       for (int j{0}; j < M; ++j) {
	           unknown[i*M+j].push_back({i,j});
	           mx[i*M+j] = grid[i][j];
	           mn[i*M+j] = grid[i][j];
	           prominence[i][j] = grid[i][j];
	       }
	   }
	}
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y, int ele) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (mn[x] > mx[y]) {
		  for (auto it = unknown[y].begin(); it != unknown[y].end(); it = next(it)) {
		  //  cout << it->first << " " << it->second << " 0" << "\n";
		    prominence[it->first][it->second] = 0;
		  }
		  unknown[y].clear();
		} else if (mn[y] > mx[x]) {
          for (auto it = unknown[x].begin(); it != unknown[x].end(); it = next(it)) {
		  //  cout << it->first << " " << it->second << " 0" << "\n";
		    prominence[it->first][it->second] = 0;
		  }
		  unknown[x].clear();
		  unknown[x].splice(unknown[x].begin(), unknown[y]);
		} else if (mx[x] == mx[y]) {
		  unknown[x].splice(unknown[x].begin(), unknown[y]);
		} else if (mx[x] > mx[y]) {
		  for (auto it = unknown[y].begin(); it != unknown[y].end(); it = next(it)) {
		  //  cout << it->first << " " << it->second << " " << grid[it->first][it->second] << " " << ele << "C " << get(y) << " " << get(x) << " " << mx[x] << " " << get(10) << "\n";
		    prominence[it->first][it->second] = grid[it->first][it->second] - ele;
		  }
		  unknown[y].clear();
		} else if (mx[y] > mx[x]) {
		  for (auto it = unknown[x].begin(); it != unknown[x].end(); it = next(it)) {
		  //  cout << it->first << " " << it->second << " " << grid[it->first][it->second] << " " << ele << "D " << get(x) << " " << get(y) << " " << mx[y] << " " << get(10) << "\n";
		    prominence[it->first][it->second] = grid[it->first][it->second] - ele;
		  }
		  unknown[x].clear();
		  unknown[x].splice(unknown[x].begin(), unknown[y]);
		}
		mn[x] = min(mn[x], mn[y]);
		if (mx[y] > mx[x]) {
		    mx[x] = mx[y];
		}
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x;
	    return 1;
	}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  int n{N}, m{M};

  for (int i{0}; i < n; ++i) {
      for (int j{0}; j < m; ++j) {
          cin >> grid[i][j];
      }
  }

  vector<pair<int,pair<int,int>>> nodes(N*M);
  for (int i{0}; i < N; ++i) {
      for (int j{0}; j < M; ++j) {
          nodes[i*M+j].first = grid[i][j];
          nodes[i*M+j].second = {i,j};
      }
  }

  sort(nodes.begin(), nodes.end(), greater<pair<int,pair<int,int>>>());
    // cout <<( find(nodes.begin(), nodes.end(), make_pair(6, make_pair(0, 7))) == nodes.end()) << "\n";

  DSU dsu;
  dsu.init(n, m);
  
  vector<int> dx = {1, -1, 0 , 0};
  vector<int> dy = {0, 0, 1, -1};
  for (auto &node: nodes) {
    for (int k{0}; k < 4; ++k) {
      if (node.second.first + dx[k] < 0 || node.second.first + dx[k] >= n || node.second.second + dy[k] < 0 || node.second.second + dy[k] >= m) {
        continue;
      }
      if (grid[node.second.first + dx[k]][node.second.second + dy[k]] >= grid[node.second.first][node.second.second]) {
        dsu.unite((node.second.first+ dx[k])*M+(node.second.second+dy[k]), node.second.first*M+node.second.second, grid[node.second.first][node.second.second]);
      }
    }
  }
  
  for (int i{0}; i < n; ++i) {
      for (int j{0}; j < m; ++j) {
          cout << prominence[i][j] << " ";
      }
      cout << "\n";
  }

  return 0;
}
