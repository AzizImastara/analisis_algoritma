#include <stdio.h>
#include <string.h>

// Constants
#define maxStringLength 100

int main() {
    int n = 0;
    scanf("%d", &n);
    char inputArray[n][maxStringLength];

    // Selection sorting
    printf("Masukkan string untuk diurutkan:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", (i + 1));
        scanf("%s", inputArray[i]);
    }

    for (int i = 0; i < n; ++i) {
        int length = strlen(inputArray[i]);
        for (int j = 0; j < length - 1; ++j) {
            for (int k = j + 1; k < length; ++k) {
                if (inputArray[i][j] > inputArray[i][k]) {
                    char temp = inputArray[i][j];
                    inputArray[i][j] = inputArray[i][k];
                    inputArray[i][k] = temp;
                }
            }
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(inputArray[i], inputArray[j]) > 0) {
                char temp[maxStringLength];
                strcpy(temp, inputArray[i]);
                strcpy(inputArray[i], inputArray[j]);
                strcpy(inputArray[j], temp);
            }
        }
    }

    // Print output
    printf("\nHasil pengurutan secara alfabetis:\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\n", inputArray[i]);
    }

    return 0;
}
