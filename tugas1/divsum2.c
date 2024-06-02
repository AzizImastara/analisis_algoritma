#include <stdio.h>
#include <math.h>

int divisor_sum(int n)
{
  int sum = 0;
  int sqrt_n = (int)sqrt(n);

  for (int i = 1; i <= sqrt_n; i++)
  {
    if (n % i == 0)
    {
      sum += i;
      if (i != n / i)
      {
        sum += n / i;
      }
    }
  }

  return sum - n;
}

int main()
{
  int num_test_cases;
  scanf("%d", &num_test_cases);

  for (int i = 0; i < num_test_cases; i++)
  {
    int num;
    scanf("%d", &num);

    int sum = divisor_sum(num);

    printf("%d\n", sum);
  }

  return 0;
}