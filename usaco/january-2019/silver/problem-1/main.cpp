#include <bits/stdc++.h>

using namespace std;

int main()
{
  ofstream fout("planting.out");
  ifstream fin("planting.in");
  int n;
  fin >> n;
  vector<int> graph[n + 1];
  for (int i{0}; i < n - 1; ++i) {
    int x, y;
    fin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  int mx{-1};
  for (int i{0}; i <= n; ++i) {
    // fout << i << " " << graph[i].size() << " ";
    // for (auto ne: graph[i]) {
    //   fout << ne << " ";
    // }
    // fout << endl;
    if (static_cast<int>(graph[i].size()) > mx) {
      mx = graph[i].size();
    }
  }
  fout << (mx + 1);
}
