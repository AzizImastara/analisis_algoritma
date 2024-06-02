#include <stdio.h>
#include <string.h>

// Swap elemen
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// membagi array menjadi 2 bagian, elemen yang kecil sebelah kiri, elemen yang besar sebelah kanan
int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fungsi ini melakukan partisi pada array berdasarkan pivot, kemudian secara rekursif memanggil dirinya sendiri untuk mengurutkan kedua subarray yang dihasilkan.
void quick_sort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Fungsi ini menerima array dua dimensi dari string dan ukuran array tersebut
void sort_chars_in_strings(char arr[][100], int size) {
    for (int i = 0; i < size; i++) {
        int len = strlen(arr[i]);
        quick_sort(arr[i], 0, len - 1);
    }
}

int main() {
    int n;
    printf("Input: \n");
    scanf("%d", &n);

    char strings[100][100];
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    sort_chars_in_strings(strings, n);

    printf("\nOutput:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
