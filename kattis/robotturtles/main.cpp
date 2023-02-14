#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

struct State {
	pii pos;
	int dir;
	bool operator<(const State &rhs) const {
		return true;
	}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // 3 state fields: pos, ice_in_front, dir
	// 8*8*2*4 = 512 states

	vector<vector<char>> board(8, vector<char>(8));
	pii turtle, end;
	for (int i{0}; i < 8; ++i) {
		for (int j{0}; j < 8; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 'T') {
				turtle = {i,j};
			} else if (board[i][j] == 'D') {
				end = {i,j};
			}
		}
	}

	// Precompute ice in front of cells
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	// map<int,int> oppd;
	// oppd[0] = 2; oppd[1] = 3; oppd[2] = 0; oppd[3] = 1;
	// vector<vector<vector<bool>>> front(4, vector<vector<bool>>(8, vector<bool>(8)));
	// for (int i{0}; i < 4; ++i) {
	// 	for (int j{0}; j < 8; ++j) {
	// 		for (int k{0}; k < 8; ++k) {
	// 			if (board[j][k] == 'I') {
	// 				int opp{oppd[i]};
	// 				pii cur{j+dx[i],k+dy[i]};
	// 				if (cur.first < 0 || cur.second >= 8 || cur.second < 0 || cur.first >= 8) continue;
	// 				if (board[cur.first][cur.second] != '.' && board[cur.first][cur.second] != 'D' && board[cur.first][cur.second] != 'T') continue;
	// 				front[opp][cur.first][cur.second] = 1;
	// 			}
	// 		}
	// 	}
	// }

	vector<vector<vector<int>>> dist(8, vector<vector<int>>(8, vector<int>(4, INT_MAX)));
	vector<vector<vector<pair<char,pair<pii,int>>>>> prevc(8, vector<vector<pair<char,pair<pii,int>>>>(8, vector<pair<char,pair<pii,int>>>(4)));
	dist[turtle.first][turtle.second][0] = 0;
	priority_queue<pair<int,State>, vector<pair<int,State>>, greater<pair<int,State>>> q;
	State start;
	start.pos = turtle;
	start.dir = 0;
	q.push({0, start});
	int cdd{-1};
	while (q.size()) {
		int d = q.top().first;
		State st = q.top().second;
		q.pop();
		if (d > dist[st.pos.first][st.pos.second][st.dir]) continue;
		if (d + 1 < dist[st.pos.first][st.pos.second][(st.dir+1)%4]) {
			dist[st.pos.first][st.pos.second][(st.dir+1)%4] = d + 1;
			prevc[st.pos.first][st.pos.second][(st.dir+1)%4] = {'R', {st.pos, st.dir}};
			cdd = st.dir;
			st.dir = (st.dir+1)%4;
			q.push({d+1, st});
			st.dir = cdd;
		}
		if (d + 1 < dist[st.pos.first][st.pos.second][(st.dir+3)%4]) {
			dist[st.pos.first][st.pos.second][(st.dir+3)%4] = d+1;
			prevc[st.pos.first][st.pos.second][(st.dir+3)%4] = {'L', {st.pos, st.dir}};
			cdd = st.dir;
			st.dir = (st.dir+3)%4;
			q.push({d + 1, st});
			st.dir = cdd;
		}
		pii nexti{st.pos};
		nexti.first += dx[st.dir];
		nexti.second += dy[st.dir];
		if (nexti.first < 0 || nexti.second < 0 || nexti.first >= 8 || nexti.second >= 8) continue;
		int cst{1};
		if (board[nexti.first][nexti.second] == 'I') cst = 2;
		if (d + cst < dist[nexti.first][nexti.second][st.dir] && (board[nexti.first][nexti.second] == 'D' || board[nexti.first][nexti.second] == '.' || cst == 2)) {
			dist[nexti.first][nexti.second][st.dir] = d + cst;
			prevc[nexti.first][nexti.second][st.dir] = {'F' + (cst - 1), {st.pos, st.dir}};
			swap(nexti, st.pos);
			q.push({d + cst, st});
			swap(nexti, st.pos);
		}
	}

	string ans;
	int mn{INT_MAX};
	for (int i{0}; i < 4; ++i) {
		if (dist[end.first][end.second][i] < mn) {
			ans = "";
			pii currr{end};
			int curd{i};
			while (true) {
				if (currr == start.pos && curd == start.dir) break;
				if (prevc[currr.first][currr.second][curd].first == 'G') {
					ans += 'F'; ans += 'X';
				} else {
					ans += prevc[currr.first][currr.second][curd].first;
				}
				int bd{curd};
				curd = prevc[currr.first][currr.second][bd].second.second;
				currr = prevc[currr.first][currr.second][bd].second.first;
			}
			reverse(ans.begin(), ans.end());
			mn = dist[end.first][end.second][i];
		}
	}

	if (mn == INT_MAX) {
		cout << "no solution\n";
	} else {
		cout << ans << "\n";
	}

  return 0;
}
