/*
ID: saiansh1
LANG: C++
TASK: namenum
*/

#include <bits/stdc++.h>

using namespace std;

bool verify(string word, string serial) {
  int i{0};
  for (auto n: serial) {
    int conversion{65 + 3 * (n - 50)};
    int diff{3};
    if (conversion == 80) {
      diff = 4;
    }
    if (word[i] >= conversion && word[i] < conversion + diff) {
      
    } else {
      return false;
    }
    ++i;
  }
  return true;
}

int main()
{
  ofstream fout("namenum.out");
  ifstream fin("namenum.in");
  ifstream dict("dict.txt");

  vector<string> d;
  for (int i{0}; i < 4617; ++i)
  {
    string x;
    dict >> x;
    d.push_back(x);
  }

  string serial;
  fin >> serial;

  bool did{0};
  for (auto &word: d) {
    if (word.size() == serial.size() && verify(word, serial)) {
      fout << word << "\n";
      did = 1;
    }
  }

  if (!did) {
    fout << "NONE" << "\n";
  }
}
