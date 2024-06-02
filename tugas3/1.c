#include <stdio.h>

int metode_ini(int arr[], int n, int key)
{
  for (int i = 0; i < n; ++i)
  {
    if (arr[i] == key)
      return i;
  }
  return -1;
}

int main()
{
  int arr[] = {10, 20, 30, 40, 50};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 30;
  int result = metode_ini(arr, n, key);
  if (result != -1)
    printf("Berhasil: %d\n", result);
  else
    printf("Tidak berhasil\n");
  return 0;
}
