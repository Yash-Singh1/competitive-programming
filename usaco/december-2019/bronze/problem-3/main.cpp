#include <bits/stdc++.h>

using namespace std;

// map names to integer
pair<string,string> constraints[7];
int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);

  cin >> n;
  string trash;
  for (int i{0}; i < n; ++i) {
    cin >> trash;
    constraints[i].first = trash;
    cin >> trash >> trash >> trash >> trash >> trash;
    constraints[i].second = trash;
  }

  string cows[8] {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
  sort(cows, cows+8);

  do {
    bool pos{1};
    for (int i{0}; i < n; ++i) {
      bool didit{0};
      for (int j{1}; j < 8; ++j) {
        if (cows[j] == constraints[i].first && cows[j - 1] == constraints[i].second) {
          didit = 1;
          break;
        } else if (cows[j] == constraints[i].second && cows[j - 1] == constraints[i].first) {
          didit = 1;
          break;
        }
      }
      if (!didit) {
        pos = 0;
        break;
      }
    }
    if (pos) {
      for (int i{0}; i < 8; ++i) {
        cout << cows[i] << "\n";
      }
      return 0;
    }
  } while ( std::next_permutation(cows,cows+8) );

  return 0;
}
