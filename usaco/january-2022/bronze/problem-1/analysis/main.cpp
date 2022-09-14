#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  char real[3][3];
  char guess[3][3];
  map<char, int> m;
  for (int i{0}; i < 3; ++i) {
    for (int j{0}; j < 3; ++j) {
      cin >> real[i][j];
      ++m[real[i][j]];
    }
  }
  for (int i{0}; i < 3; ++i) {
    for (int j{0}; j < 3; ++j) {
      cin >> guess[i][j];
    }
  }
  int g{0}, y{0};
  for (int i{0}; i < 3; ++i) {
    for (int j{0}; j < 3; ++j) {
      if (real[i][j] == guess[i][j]) {
        ++g;
        --m[real[i][j]];
      }
    }
  }
  for (int i{0}; i < 3; ++i) {
    for (int j{0}; j < 3; ++j) {
      if (m[guess[i][j]] > 0 && real[i][j] != guess[i][j]) {
        //cout << i << " " << j << endl;
        ++y;
        --m[guess[i][j]];
      }
    }
  }
  cout << g << endl << y << endl;
}
