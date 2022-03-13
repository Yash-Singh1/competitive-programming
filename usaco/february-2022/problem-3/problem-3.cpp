#include <iostream>
#include <ios>
#include <map>
#include <vector>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  std::map<char, bool> blocks[4];
  int i{5};
  while (--i) {
    int j{7};
    while (--j) {
      char c;
      cin >> c;
      blocks[4 - i][c] = true;
    }
  }
  ++n;
  while (--n) {
    std::string word;
    cin >> word;
    char used[4] {'\0', '\0', '\0', '\0'};
    bool yas{true};
    for (auto letter: word) {
      std::vector<int> posses;
      for (int j{0}; j < 4; ++j) {
        if (blocks[j].find(letter) != blocks[j].end() && !used[j]) {
          posses.push_back(j);
        }
      }
      int usedPos{-1};
      int usedPosCounts{-1};
      if (posses.size() > 1) {
        for (auto pos: posses) {
          if (usedPos != -1 && usedPosCounts == -1) break;
          int noPos{0};
          for (long unsigned int j{0}; j < word.size(); ++j) {
            if (blocks[pos].find(word[j]) != blocks[pos].end()) {
              ++noPos;
            }
          }
          if (noPos == 0) {
            usedPos = pos;
            usedPosCounts = 0;
          } else {
            if (noPos < usedPosCounts || usedPosCounts == -1) {
              usedPos = pos;
              usedPosCounts = noPos;
            }
          }
        }
      } else if (posses.size() == 1) {
        usedPos = posses[0];
      } else {
        std::cout << "NO" << std::endl;
        yas = false;
        break;
      }
      used[usedPos] = true;
    }
    if (yas) {
      std::cout << "YES" << std::endl;
    }
  }
}
