#include <stdio.h>

int main () {
    char coordinates[11][11];
    int i;
    int j;

    /* fill the field with spaces */
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 11; j++) {
            coordinates[i][j] = ' ';
        }
    }

    /* set the border */
    coordinates[0][1] = '1';
    coordinates[0][2] = '2';
    coordinates[0][3] = '3';
    coordinates[0][4] = '4';
    coordinates[0][5] = '5';
    coordinates[0][6] = '6';
    coordinates[0][7] = '7';
    coordinates[0][8] = '8';

    coordinates[9][1] = '1';
    coordinates[9][2] = '2';
    coordinates[9][3] = '3';
    coordinates[9][4] = '4';
    coordinates[9][5] = '5';
    coordinates[9][6] = '6';
    coordinates[9][7] = '7';
    coordinates[9][8] = '8';

    coordinates[1][0] = '1';
    coordinates[2][0] = '2';
    coordinates[3][0] = '3';
    coordinates[4][0] = '4';
    coordinates[5][0] = '5';
    coordinates[6][0] = '6';
    coordinates[7][0] = '7';
    coordinates[8][0] = '8';

    coordinates[1][9] = '1';
    coordinates[2][9] = '2';
    coordinates[3][9] = '3';
    coordinates[4][9] = '4';
    coordinates[5][9] = '5';
    coordinates[6][9] = '6';
    coordinates[7][9] = '7';
    coordinates[8][9] = '8';

    /* set the seed */
    coordinates[3][3] = 'O';
    coordinates[3][4] = 'O';
    coordinates[4][4] = 'O';
    coordinates[4][5] = 'O';
    coordinates[5][4] = 'O';

    /* print the whole field */
    for(i = 0; i < 11; i++) {
        for (j = 0; j < 11; j++) {
            printf("%c ", coordinates[i][j]);
        }
        puts("");
    }
    return 0;
}
