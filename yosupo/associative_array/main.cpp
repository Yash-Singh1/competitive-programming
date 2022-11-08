#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  map<ll,ll>m;
  ll q;
  cin >> q;
  
  ll t, x, y;
  while (q--) {
    cin >> t;
    if (t == 0) {
      cin >> x >> y;
      m[x]=y;
    } else {
      cin >> x;
      cout << m[x] << "\n";
    }
  }

  return 0;
}
