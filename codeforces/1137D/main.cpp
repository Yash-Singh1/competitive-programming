#include <bits/stdc++.h>

using namespace std;

string dump;

int together{-1};
void dumpit() {
  for (int i{0}; i < together; ++i) cin >> dump;
}

int main() {
  ios_base::sync_with_stdio(false);

  while (together == -1 || together > 2) {
    cout << "next 0 1" << endl;
    cin >> together;
    dumpit();
    cout << "next 1" << endl;
    cin >> together;
    dumpit();
  }

  while (together != 1) {
    cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
    cin >> together;
    dumpit();
  }

  cout << "done" << endl;

  return 0;
}
