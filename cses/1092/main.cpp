#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  if ((n*(n+1)/2) & 1) {
    cout << "NO\n";
    return 0;
  }

  ll left{(n*(n+1))/4};
  vector<ll> first, second;
  for (ll i{n}; i >= 1; --i) {
    if (left >= i) {
      left -= i;
      first.push_back(i);
    } else {
      second.push_back(i);
    }
  }

  cout << "YES\n";
  cout << first.size() << "\n";
  for (auto &el: first) cout << el << " ";
  cout << "\n";
  cout << second.size() << "\n";
  for (auto &el: second) cout << el << " ";
  cout << "\n";

  return 0;
}
