/*
ID: saiansh1
LANG: C++
TASK: transform
*/

#include <bits/stdc++.h>

using namespace std;

void rot90(string in[], int n) {
  map<int, map<int, bool>> m;
  for (int i{0}; i < n; ++i) {
    for (int j{0}; j < n; ++j) {
      if (m[i][j]) {
        continue;
      }
      // j, n - 1 - i
      int ni{j}, nj{n - 1 - i};
      vector<pair<int, int>> v;
      v.push_back({i, j});
      v.push_back({ni, nj});
      for (int k{0}; k < 2; ++k) {
        int swp{ni};
        ni = nj;
        nj = n - 1 - swp;
        v.push_back({ni, nj});
      }
      if (ni == i && nj == j) {
        continue;
      } else {
        int storeVal{in[v[0].first][v[0].second]};
        for (size_t k{0}; k < v.size(); ++k)
        {
          pair<int, int> *next{&v[(k == v.size() - 1 ? 0 : k + 1)]};
          int swpstoreval{in[next->first][next->second]};
          in[next->first][next->second] = storeVal;
          storeVal = swpstoreval;
          m[next->first][next->second] = true;
        }
      }
    }
  }
}

void rotx(string in[], int n, int x) {
  for (int i{0}; i < x / 90; ++i) {
    rot90(in, n);
  }
}

bool identical(string a[], string b[], int n) {
  for (int i{0} ; i < n; ++i) {
    for (int j {0} ; j < n; ++j) {
      if (a[i][j] != b[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void copy2arrays(string a[], string b[], int n) {
  for (int i{0}; i < n; ++i) {
    b[i] = a[i];
  }
}

void reflect(string in[], int n) {
  for (int i{0}; i < n; ++i) {
    reverse(in[i].begin(), in[i].end());
  }
}

int main()
{
  ofstream fout("transform.out");
  ifstream fin("transform.in");

  int n;
  fin >> n;
  string s1[n], s2[n];
  for (int i{0}; i < n; ++i) {
    fin >> s1[i];
  }
  for (int i{0}; i < n; ++i) {
    fin >> s2[i];
  }

  string s3[n];
  copy2arrays(s1, s3, n);
  for (int i{1}; i < 4; ++i) {
    rot90(s3, n);
    if (identical(s2, s3, n)) {
      fout << i << "\n";
      return 0;
    }
  }

  copy2arrays(s1, s3, n);
  reflect(s3, n);
  if (identical(s2, s3, n)) {
    fout << 4 << "\n";
    return 0;
  }
  for (int i{1}; i < 4; ++i) {
    rot90(s3, n);
    if (identical(s2, s3, n)) {
      fout << 5 << "\n";
      return 0;
    }
  }

  if (identical(s1, s2, n)) {
    fout << 6 << "\n";
    return 0;
  }

  fout << 7 << "\n";
  return 0;
}
