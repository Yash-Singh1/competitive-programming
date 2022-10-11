#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h;
    string s;
    cin >> s;
    int switches{0};
    for (int i{0}; i < n; ++i) {
      if (s[i] == '0' && c1 - c0 < -h) {
        switches += h;
        s[i] = '1';
        switches += c1;
      } else if (s[i] == '1' && c0 - c1 < -h) {
        switches += h;
        s[i] = '0';
        switches += c0;
      } else {
        switches += s[i] == '1' ? c1 : c0;
      }
    }
    cout << switches << "\n";
  }
}
