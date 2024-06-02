#include <iostream>
using namespace std;
// menggunakan namespace 'std' sehingga tidak perlu lagi menuliskan std::

int binarySearch(int arr[], int low, int high, int key)
// fungsi yang mengembalikan indeks dari nilai key ke dalam array jika ditemukan
{
  while (low <= high)
  // agar low tidak melebihi high
  {
    int mid = low + (high - low) / 2;
    // menghitung indeks tengah
    if (arr[mid] == key)
      return mid;
    else if (arr[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
    // jika nilai key lebih dari mid maka +1 jika kurang dari mid maka -1
  }
  return -1;
  // jika nilai tidak ditemukan maka fungsi mengembalikan -1
}

int main()
{
  int arr[] = {10, 20, 30, 40, 50};
  int n = sizeof(arr) / sizeof(arr[0]);
  int key = 30;
  int result = binarySearch(arr, 0, n - 1, key);
  if (result != -1)
    cout << "Berhasil: " << result << endl;
  else
    cout << "Tidak berhasil" << endl;
  // jika nilai yang dicari ditemukan maka print "Berhasil" jika tidak maka "Tidak berhasil"
  return 0;
}
