#include <bits/stdc++.h>

using namespace std;

int validate(char board[8][8], vector<bool> col, set<int> s, set<int> s2, int done) {
  if (done == 8) {
    return 1;
  } else {
    int sm{0};
    for (int i{0}; i < 8; ++i) {
      if (board[done][i] == '.' && !col[i] && s.find((8-done)-i) == s.end() && s2.find((8-done)+i) == s2.end()) {
        col[i] = 1;
        auto erasepoint = s.insert((8-done)-i).first;
        auto erasepoint2 = s2.insert((8-done)+i).first;
        sm += validate(board,col,s,s2,done+1);
        s.erase(erasepoint);
        s2.erase(erasepoint2);
        col[i]=0;
      }
    }
    return sm;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<bool> col(8);
  set<int> s;
  set<int> s2;

  char board[8][8];
  for (int i{0}; i < 8; ++i) {
    for (int j{0}; j < 8; ++j) {
      cin >> board[i][j];
    }
  }

  cout << validate(board, col, s, s2, 0) << "\n";

  return 0;
}
