#include <stdio.h>

int take(int x, int y, int** arr) {
    return arr[x][y];
}

int main() {
    int kek;
    int kekek;
    int twod[2][2] = {{1, 2}, {3, 4}};
    printf("%d\n", take(1, 1, twod));

    return 0;
}