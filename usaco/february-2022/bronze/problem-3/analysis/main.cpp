#include <bits/stdc++.h>

using namespace std;

string die[4];

bool can_make(string word, map<int, bool> r) {
    if (word.size() == 0) {
        return true;
    }
    char first{word[0]};
    word = word.substr(1, word.size() - 1);
    bool canmakeinend{false};
    for (int i{0}; i < 4; ++i) {
        if (r.find(i) == r.end()) {
            bool g{false};
            for (auto ch: die[i]) {
                if (ch == first) {
                    g = 1;
                    break;
                }
            }
            if (g) {
                r[i] = 1;
                if (can_make(word, r)) {
                    canmakeinend = true;
                    break;
                }
                r.erase(i);      
            }
        }
    }
    if (canmakeinend) {
        return true;
    }
    return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  cin >> die[0] >> die[1] >> die[2] >> die[3];
  while (n--) {
    string word;
    cin >> word;
    map<int, bool> r;
    if (can_make(word, r)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
  }
}
