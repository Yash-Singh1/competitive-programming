/*
ID: saiansh1
LANG: C++
TASK: test
*/

#include <fstream>

using namespace std;

int main()
{
  ofstream fout("test.out");
  ifstream fin("test.in");
  int x, y;
  fin >> x >> y;
  fout << x + y << endl;
}
