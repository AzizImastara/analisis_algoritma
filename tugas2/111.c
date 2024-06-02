#include <stdio.h>

int main(void)
{

  int n;
  while (scanf("%d", &n) && n <= 99)
  {
    if (n == 42)

      break;

    else

      printf("%d\n", n);
  }

  return 0;
}