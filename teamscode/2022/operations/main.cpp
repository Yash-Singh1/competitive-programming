#include <iostream>
#include <ios>
#include <set>

using std::cin;

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  ++n;
  while (--n)
  {
    int a, b;
    cin >> a >> b;
    std::set<float> op;
    op.insert(a + b);
    op.insert(a - b);
    op.insert(a * b);
    op.insert(static_cast<float>(a) / b);
    op.insert(b - a);
    op.insert(static_cast<float>(b) / a);
    std::cout << op.size() << std::endl;
  }
}
