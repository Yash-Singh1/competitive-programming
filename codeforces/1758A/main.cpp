#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  string s; 
  while (t--) {
    cin >> s;
    for (int i{0}; i < s.size(); ++i) {
      cout << s[i];
    }
    for (int i{s.size() - 1}; i >= 0; --i) {
      cout << s[i];
    }
    cout << "\n";
  }

  return 0;
}
