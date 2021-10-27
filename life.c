#include <stdio.h>

int main () {
    int y = 10;
    int x = 10;
    char coordinates[y][x];

    /* fill the field with spaces and set borders */
    for (short i = 0; i < y; i++) {
        for (short j = 0; j < x; j++) {
            if ((i == 0 || i == y - 1) && (j > 0 && j < x - 1)) {
                coordinates[i][j] = j + '0';
            }
            else if ((j == 0 || j == x - 1) && (i > 0 && i < y - 1)) {
                coordinates[i][j] = i + '0';
            }
            else {
                coordinates[i][j] = ' ';
            }
        }
    }

    /* set the seed * /
    coordinates[3][3] = 'O';
    coordinates[3][4] = 'O';
    coordinates[4][4] = 'O';
    coordinates[4][5] = 'O';
    coordinates[5][4] = 'O';

    /* print the whole field */
    for (short i = 0; i < y; i++) {
        for (short j = 0; j < x; j++) {
            printf("%c ", coordinates[i][j]);
        }
        puts("");
    }

    printf("\nPlease input dot coordinates for the seed (x, y, Enter).\nDot 1: ");
    puts("");

    return 0;
}
