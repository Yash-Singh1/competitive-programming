// top-down dp here gives TLE on half of TCs
// bottom-up dp has lots of state requirements so I'll revisit this problem later
// We can remove the sum of group part of the expression and just sum up the max of each group * the number of elements
// In the end we can subtract the entire thing by the sum of the array

#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a(400);
// vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(n, 0)));
vector<vector<unordered_map<int,int>>> dp(401, vector<unordered_map<int,int>>(401));
// vector<vector<int>> dp(401, vector<int>(401, -1));

int mx(int id, int left, int mxe, int l) {
  if (id == n) {
    return 0;
  }
  if (left == -1) {
    return 1e9;
  }
  mxe = max(mxe, a[id]);
  ++l;
  if (dp.at(id).at(left).find(l) != dp.at(id).at(left).end()) {
  // if (dp[id][left] != -1) {
    return dp.at(id).at(left)[l];
  }
  return (dp.at(id).at(left)[l] = min(mx(id + 1, left - 1, 0, 0) + (mxe * l), mx(id + 1, left, mxe, l) + (id + 1 == n ? (mxe * l) : 0)));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("snakes.in", "r", stdin);
  freopen("snakes.out", "w", stdout);

  cin >> n >> k;

  int sm{0};
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
    sm += a[i];
  }

  // dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + 
  // int ans{INT_MAX};
  // for (int i{0}; i < n; ++i) {
  //   for (int j{0}; j < k; ++j) {
      
  //   }
  // }

  cout << mx(0, k, 0, 0)-sm << "\n";

  return 0;
}
