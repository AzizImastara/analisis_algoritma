#include <stdio.h>

struct Life
{
  int *inputArray;
  int length;
};

void printResult(struct Life *life)
{
  printf("Started\n");
  for (int i = 0; i < life->length; i++)
  {
    if (life->inputArray[i] == 42 && (life->inputArray[i] > 99) && (life->inputArray[i] < -99))
      break;
    printf("%d\n", life->inputArray[i]);
  }
  printf("FINISHED\n");
}

int main()
{
  int c[] = {1, 3, 4, 5, 1, 2, 3, 7, 8, 9, 0, 1, 2, 3, 42, 4, 5, 6, 7, 8, 4};
  struct Life ob;
  ob.inputArray = c;
  ob.length = sizeof(c) / sizeof(c[0]);
  printResult(&ob);
  return 0;
}
