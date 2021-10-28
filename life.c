#include <stdio.h>

int main () {
    int y = 10;
    int x = 10;
    char coordinates[y][x];

    /* fill the field with spaces and set borders */
    for (short i = 0; i < y; i++) {
        for (short j = 0; j < x; j++) {
            if ((i == 0 || i == y - 1) && (j > 0 && j < y - 1)) {
                coordinates[i][j] = j + '0';
            }
            else if ((j == 0 || j == y - 1) && (i > 0 && i < y - 1)) {
                coordinates[i][j] = i + '0';
            }
            else {
                coordinates[i][j] = ' ';
            }
        }
    }

    /* set the seed */
    coordinates[4][3] = 'O';
    coordinates[4][4] = 'O';
    coordinates[4][5] = 'O';

    /* print the whole field */
    for (short i = 0; i < y; i++) {
        for (short j = 0; j < x; j++) {
            printf("%c ", coordinates[i][j]);
        }
        puts("");
    }

    /* check a cell for neighbors */
    int neighbors_count = 0;
    for (short i = 0; i < y; i++) {
        for (short j = 0; j < x; j++) {
            if (coordinates[i][j] != ' ') {
                for (short i = -1; i < 1; i++) {
                  /* code */
                }
            }
            printf("%c ", coordinates[i][j]);
        }
        puts("");
    }

    return 0;
}
