#include <stdio.h>

void towerOfHanoi(int n, int dari_tiang, int tiang_bantuan, int tujuan) {
    char *tiang[] = {"Base of Power", "Tower of Triumph", "Booster Platform"};

    if (n == 1) {
        printf("Pindahkan gelang 1 dari %s ke %s\n", tiang[dari_tiang - 1], tiang[tiang_bantuan - 1]);  
        return;
    }

    towerOfHanoi(n - 1, dari_tiang, tujuan, tiang_bantuan);
    printf("Pindahkan gelang %d dari %s ke %s\n", n, tiang[dari_tiang - 1], tiang[tiang_bantuan - 1]);
    towerOfHanoi(n - 1, tujuan, tiang_bantuan, dari_tiang);
}

int main() {
    int T, round;
    scanf("%d", &T);
    int rounds[T];
    for (round = 0; round < T; round++) {
        scanf("%d", &rounds[round]);
    }
    for (round = 0; round < T; round++) {
        printf("Ronde %d:\n", round + 1);
        printf("Langkah-langkah epik Anto dalam memindahkan gelang:\n");
        towerOfHanoi(rounds[round], 1, 2, 3);
    }
    return 0;
}
