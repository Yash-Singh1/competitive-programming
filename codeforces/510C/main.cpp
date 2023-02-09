#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // Form a graph between characters and run toposort on it
  int n;
  cin >> n;

  vector<string> a(n);
  for (int i{0}; i < n; ++i) {
    cin >> a[i];
  }

  vector<vector<bool>> g(26, vector<bool>(26));
  for (int i{0}; i < n-1; ++i) {
    bool succ{0};
    for (int j{0}; j < (int)min(a[i].size(), a[i + 1].size()); ++j) {
      if (a[i][j] != a[i + 1][j]) {
        // cout << a[i][j] << " " << a[i + 1][j] << "\n";
        g[a[i][j] - 'a'][a[i + 1][j] - 'a'] = 1;
        succ = 1;
        break;
      }
    }
    if (!succ && a[i].size() > a[i + 1].size()) {
      cout << "Impossible\n";
      return 0;
    }
  }

  stack<int> s;
  vector<int> in(26);
  for (int j{0}; j < 26; ++j) {
    for (int i{0}; i < 26; ++i) {
      if (g[i][j]) ++in[j];
    }
    if (!in[j]) {
      s.push(j);
    }
  }
  // for (int i{0}; i < 26; ++i) cout << in[i] << " ";
  // cout << "\n";
  string ans;
  while (s.size()) {
    int u = s.top();
    s.pop();
    ans += u + 'a';
    for (int i{0}; i < 26; ++i) {
      if (g[u][i]) {
        --in[i];
        if (in[i] < 0) {
          cout << "Impossible\n";
          return 0;
        }
        if (!in[i]) {
          s.push(i);
        }
      }
    }
  }

  // cout << ans << "\n";
  if (ans.size() == 26) {
    cout << ans << "\n";
  } else {
    cout << "Impossible\n";
  }

  return 0;
}
