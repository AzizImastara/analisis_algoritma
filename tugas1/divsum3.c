#include <stdio.h>
#include <math.h>

int divisor_sum(int n)
{
  int sum = 1;
  int sqrt_n = (int)sqrt(n);

  for (int i = 2; i <= sqrt_n; i++)
  {
    if (n % i == 0)
    {
      sum += i;
      if (n / i != i)
      {
        sum += n / i;
      }
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
