/*
ID: saiansh1
LANG: C++
TASK: barn1
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("barn1.out");
  ifstream fin("barn1.in");
  int m,s,c;
  fin >> m >> s >> c;
  int lst{-1};
  int sm{0};
  priority_queue<int> pq;
  int sc{c};
  vector<int> input;
  for (int i{0}; i < c; ++i) {
    int x;
      fin >> x;
      input.push_back(x);
  }
    sort(input.begin(), input.end());
  for(int i{0}; i < c; ++i) {
    int x{input[i]};
    if (lst != -1 && lst != x - 1) {
      int d{x - lst - 1};
      sm += d;
      pq.push(d);
    }
    lst = x;
  }
  for (int i{0}; (i < m - 1 && !pq.empty()); ++i) {
    int next{pq.top()};
    pq.pop();
    sm -= next;
  }
  fout << (sm + sc) << "\n";
}
