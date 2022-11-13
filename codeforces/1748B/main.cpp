#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  char s[100001];
  int t;
  cin >> t;
  int n;
  int ml{0};
  while (t--) {
    cin >> n;
    for (int i{0}; i < n; ++i) {
      cin >> s[i];
    }
    int tot{0};
    for (int i{0}; i < n; ++i) {
      unordered_map<int, int> freq;
      ml = 1;
      for (int j{i}; j < i+100 && j < n; ++j) {
        ++freq[s[j]];
        ml = max(ml, freq[s[j]]);
        if (ml <= freq.size()) {
          ++tot;
        }
      }
    }
    cout << tot << "\n";
  }

  return 0;
}
