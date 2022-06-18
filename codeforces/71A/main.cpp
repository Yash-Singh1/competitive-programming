#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  ++n;
  while (--n) {
    string x;
    cin >> x;
    if (x.size() > 10) {
      cout << x[0] << x.size() - 2 << x[x.size() - 1] << endl;
    } else {
      cout << x << endl;
    }
  }
}
