#include <stdio.h>

int divisor_sum(int n)
{
  int sum = 0;
  for (int i = 1; i <= n / 2; i++)
  {
    if (n % i == 0)
    {
      sum += i;
    }
  }
  return sum;
}

int main()
{
  int test_cases, num;
  scanf("%d", &test_cases);

  for (int i = 0; i < test_cases; i++)
  {
    scanf("%d", &num);
    printf("%d\n", divisor_sum(num));
  }

  return 0;
}
