#include <set>
#include <iostream>

int main()
{
  std::set<int> moduli;
  for (size_t i = 0; i < 10; i++)
  {
    int num;
    std::cin >> num;
    moduli.insert(num % 42);
  }
  std::cout << moduli.size();
}
