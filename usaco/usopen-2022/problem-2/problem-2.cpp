#include <iostream>
#include <ios>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int gthan{-1};
  int lthan{-1};
  int oof{0};
  while (n--) {
    char spec;
    cin >> spec;
    int mag;
    cin >> mag;
    if ((spec == 'G' && (lthan != -1 && lthan <= mag)) || (spec == 'L' && (gthan != -1 && gthan >= mag))) ++oof;
    else {
      if (spec == 'G' && gthan < mag) gthan = mag;
      if (spec == 'L' && lthan == -1 && lthan > mag) lthan = mag;
    }
  }
  std::cout << oof;
}
