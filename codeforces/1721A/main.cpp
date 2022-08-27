#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;

++t;
while (--t) {
  int chc[26];
  for (int i{0}; i < 26; ++i) {
    chc[i] = 0;
  }
  for (int i{0}; i < 4; ++i) {
    char ch;
    cin >> ch;
    chc[ch - 'a']++;
  }
  int ms{0};
  int to{-1};
  for (int i{0}; i < 26; ++i) {
    if (chc[i] > 1) {
        to = i;
        break;
    } else if (chc[i] == 1) {
        to = i;
    }
  }

  for (int i{0}; i < 26; ++i) {
    if (i != to && chc[i] > 0) {
        ++ms;
    }
  }

  cout << ms << endl;
}
  
  return 0;
}
