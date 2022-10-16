#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;

  cin >> n;

  map<string, bool> m;

  for (int i{0}; i < n; ++i) {
    string type, name;
    cin >> type >> name;
    if (type == "entry") {
      cout << name << " entered";
      if (m.find(name) != m.end() && m[name]) {
        cout << " (ANOMALY)";
      }
      cout << "\n";
      m[name] = 1;
    } else {
      cout << name << " exited";
      if ((m.find(name) != m.end() && !m[name]) || m.find(name) == m.end()) {
        cout << " (ANOMALY)";
      }
      cout << "\n";
      m[name] = 0;
    }
  }

  return 0;
}
