#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  ll pos;
  while (cin >> s) {
    cin >> pos;
    for (ll i{0}; i < ((int)(s.size())); ++i) {
      if (i == ((int)(s.size())-pos)) {
        cout << s[i];
      } else if (i < ((int)(s.size())-pos)) {
        cout << ((s[((int)(s.size())-pos)]-'0')+(s[i]-'0'))%10;
      } else {
        cout << abs((s[((int)(s.size())-pos)]-'0')-(s[i]-'0'));
      }
    }
    cout << "\n";
  }

  return 0;
}
