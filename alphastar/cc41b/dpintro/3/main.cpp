#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mat;
int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  mat.assign(n, vector<int>(n));
  vector<vector<int>> mxnx(n, vector<int>(n, -1));

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j <= i; ++j) {
      cin >> mat[i][j];
    }
  }
  for (int i = n-2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      if (mat[i+1][j] > mat[i+1][j+1]) {
        mxnx[i][j] = 0;
      } else {
        mxnx[i][j] = 1;
      }
      mat[i][j] = mat[i][j] + max(mat[i+1][j], mat[i+1][j+1]);
    }
  }
  cout << mat[0][0] << '\n';
  pair<int,int> cur{0,0};
  while (true) {
    cout << mat[cur.first][cur.second]-(cur.first<n-1?mat[cur.first+1][cur.second+mxnx[cur.first-1][cur.second]]:0) << ' ';
    ++cur.first;
    if (cur.first >= n) break;
    cur.second += mxnx[cur.first-1][cur.second];
  }
  cout << '\n';

  return 0;
}
