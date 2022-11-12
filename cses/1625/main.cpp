#include <bits/stdc++.h>

using namespace std;

int spec[48];
int movementsx[4] {1, -1, 0, 0};
int movementsy[4] {0, 0, -1, 1};
bool grid[9][9];
pair<int,int> loc{1,1};
int tot{0};

int pos() {
  if (loc.first == 7 && loc.second == 1) {
    if (tot == 48) return 1;
    return 0;
  }
  if (tot == 48) {
    return 0;
  }
  if (grid[loc.first-1][loc.second] && grid[loc.first+1][loc.second] && !grid[loc.first][loc.second-1] && !grid[loc.first][loc.second+1]) {
    return 0;
  }
  if (grid[loc.first][loc.second-1] && grid[loc.first][loc.second+1] && !grid[loc.first-1][loc.second] && !grid[loc.first+1][loc.second]) {
    return 0;
  }
  int sm{0};
  ++tot;
  grid[loc.first][loc.second] = 1;
  int i{spec[tot-1] == 4 ? 0 : spec[tot-1]};
  HERE: {
    if (!grid[loc.first + movementsx[i]][loc.second + movementsy[i]]) {
      loc.first += movementsx[i];
      loc.second += movementsy[i];
      sm += pos();
      loc.first -= movementsx[i];
      loc.second -= movementsy[i];
    }
  }
  if (i < 3 && spec[tot-1] == 4) {
    ++i;
    goto HERE;
  }
  --tot;
  grid[loc.first][loc.second] = 0;
  return sm;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  char x;
  for (int i{0}; i < 48; ++i) {
    cin >> x;
    if (x == 'D') {
      spec[i] = 0;
    } else if (x == 'U') {
      spec[i] = 1;
    } else if (x == 'L') {
      spec[i] = 2;
    } else if (x == 'R') {
      spec[i] = 3;
    } else {
      spec[i] = 4;
    }
  }

  for (int j{1}; j <= 7; ++j) {
    for (int i{1}; i <= 7; ++i) {
      grid[j][i] = 0;
    }
  }
  for (int i{0}; i < 9; ++i) {
    grid[0][i] = 1;
    grid[i][0] = 1;
    grid[8][i] = 1;
    grid[i][8] = 1;
  }

  cout << pos() << "\n";

  return 0;
}
