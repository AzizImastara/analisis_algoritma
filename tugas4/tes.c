#include <stdio.h>
#include <string.h>

// Constants
#define maxStringLength 100

// Function to swap two strings
void swap(char* str1, char* str2) {
    char temp[maxStringLength];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

// Function to partition the array
int partition(char arr[][maxStringLength], int low, int high) {
    char pivot[maxStringLength];
    strcpy(pivot, arr[high]);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quicksort function
void quicksort(char arr[][maxStringLength], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    char inputArray[n][maxStringLength];

    // Input strings
    printf("Masukkan string untuk diurutkan:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", (i + 1));
        scanf("%s", inputArray[i]);
    }

    // Perform Quicksort
    quicksort(inputArray, 0, n - 1);

    // Print output in reversed order
    printf("\nHasil pengurutan secara alfabetis :\n");
    for (int i = n - 1; i >= 0; --i) {
    int length = strlen(inputArray[i]);
    for (int j = length - 1; j >= 0; --j) {
        printf("%c", inputArray[i][j]);
    }
    printf("\n");


}


    return 0;
}
