#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  printf("%s", n % 2 == 0 ? "Bob" : "Alice");
}
