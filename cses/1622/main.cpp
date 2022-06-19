#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string x;
  cin >> x;
  sort(x.begin(), x.end());
  vector<string> p;
  int tot{0};
  do {
    ++tot;
    p.push_back(x);
  } while (next_permutation(x.begin(), x.end()));
  cout << tot << "\n";
  for (auto pp: p) {
    cout << pp << "\n";
  }
}
