#include <iostream>
#include <ios>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  std::string seq;
  cin >> seq;
  bool messclean{false};
  int change{0};
  while (!messclean)
  {
    messclean = true;
    int gees{0};
    int nextgees{0};
    for (int i{2}; i <= n; i += 2)
    {
      if (seq[i - 1] == 'G')
        ++gees;
      if (seq[i - 2] == 'G')
        ++nextgees;
    }
    for (int i{n % 2 == 0 ? n : n - 1}; i > 0; i -= 2)
    {
      int nextgeees{gees};
      if (seq[i - 1] == 'G')
        --nextgeees;
      int nextnextgees{nextgees};
      if (seq[i - 2] == 'G')
        --nextnextgees;
      if (nextgees > gees)
      {
        std::cout << i << ' ' << gees << ' ' << nextgees << std::endl;
        messclean = false;
        std::reverse(seq.begin(), seq.begin() + i);
        gees = nextgeees;
        nextgees = nextnextgees;
        break;
      }
      gees = nextgeees;
      nextgees = nextnextgees;
    }
    std::cout << seq << std::endl;
    ++change;
    if (change > 10)
      break;
  }
  std::cout << change;
}
