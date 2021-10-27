#include <stdio.h>

int main () {
<<<<<<< HEAD
<<<<<<< HEAD
    int y = 10;
    int x = 10;
=======
    int y = 20;
    int x = 20;
>>>>>>> e2f662211e2c3a03868938b4a5eaf8de0be4ceef
=======
    int y = 10;
    int x = 10;

>>>>>>> 2e2b424dae0b7429a0f750b6136671ce15740a57
    char coordinates[y][x];

    /* fill the field with spaces and set borders */
    for (short i = 0; i < y; i++) {
        for (short j = 0; j < x; j++) {
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 2e2b424dae0b7429a0f750b6136671ce15740a57
            if ((i == 0 || i == y - 1) && (j > 0 && j < x - 1)) {
                coordinates[i][j] = j + '0';
            }
            else if ((j == 0 || j == x - 1) && (i > 0 && i < y - 1)) {
<<<<<<< HEAD
=======
            if ((i == 0 || i == y - 1) && (j > 0 && j < y - 1)) {
                coordinates[i][j] = j + '0';
            }
            else if ((j == 0 || j == y - 1) && (i > 0 && i < y - 1)) {
>>>>>>> e2f662211e2c3a03868938b4a5eaf8de0be4ceef
=======
>>>>>>> 2e2b424dae0b7429a0f750b6136671ce15740a57
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
