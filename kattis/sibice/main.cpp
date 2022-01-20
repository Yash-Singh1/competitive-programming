#include <cstdio>
#include <cmath>

int main()
{
  int n, w, h;
  scanf("%d %d %d", &n, &w, &h);
  double minimum{pow((w * w + h * h), 0.5)};
  for (int i = 0; i < n; i++)
  {
    int l;
    scanf(" %d", &l);
    if (static_cast<double>(l) <= minimum) {
      printf("DA\n");
    } else {
      printf("NE\n");
    }
  }
}
