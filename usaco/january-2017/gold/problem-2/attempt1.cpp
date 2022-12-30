#include <bits/stdc++.h>

using namespace std;

int n;
vector<char> seq(100000);
int dp[100000][21];
map<char, int> m{{'H', 0}, {'P', 2}, {'S', 1}};
int choices[3] {'H', 'S', 'P'};

int mseq(int pos, int left) {
  if (dp[pos][left] != -1) {
    return dp[pos][left];
  }
  if (left == 0) {
    int tot{0};
    for (int j{0}; j < 3; ++j) {
      int tote{0};
      for (int i{pos}; i < n; ++i) {
        if (seq[i] == choices[j]) {
          ++tote;
        }
      }
      tot = max(tot, tote);
    }
    dp[pos][left] = tot;
    return tot;
  }
  if (pos == n - 1) {
    return 1;
  }
  int ans{0};
  int scored[3] {0, 0, 0};
  for (int j{1}; j + pos < n; ++j) {
    ++scored[m[seq[pos + j - 1]]];
    ans = max(mseq(pos + j, left - 1) + max(scored[0], max(scored[1], scored[2])), ans);
  }
  dp[pos][left] = ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);

  int k;
  cin >> n >> k;

  for (int i{0}; i < n; ++i) {
    cin >> seq[i];
  }

  for (int i{0}; i < n; ++i) {
    for (int j{0}; j <= k; ++j) {
      dp[i][j] = -1;
    }
  }

  // cout << mseq(0, k, 'H') << " " << mseq(0, k, 'S') << " " << mseq(0, k, 'P') << "\n";
  cout << mseq(0, k) << "\n";

  // int scored[3] {0, 0, 0};
  // for (int i{0}; i < n; ++i) {
  //   ++scored[m[seq[i]]];
  //   dp[i][0] = max(scored[0], max(scored[1], scored[2]));
  // }

  // for (int i{1}; i <= k; ++i) {
  //   for (int j{n-1}; j >= 0; ++j) {

  //   }
  // }

  return 0;
}
