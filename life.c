#include <stdio.h>

int main () {
    char coordinates[10][10];
    int i;
    int j;

    /* fill the field with spaces and set borders */
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if ((i == 0 || i == 9) && (j > 0 && j < 9)) {
                coordinates[i][j] = j + '0';
            }
            else if ((j == 0 || j == 9) && (i > 0 && i < 9)) {
                coordinates[i][j] = i + '0';
            }
            else {
                coordinates[i][j] = ' ';
            }
        }
    }

    /* set the seed */
    coordinates[3][3] = 'O';
    coordinates[3][4] = 'O';
    coordinates[4][4] = 'O';
    coordinates[4][5] = 'O';
    coordinates[5][4] = 'O';

    /* print the whole field */
    for(i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c ", coordinates[i][j]);
        }
        puts("");
    }
    return 0;
}
