#include <stdio.h>
#include <unistd.h>

int y = 7;
int x = 7;
char coordinates[7][7];

/* print the whole field */
void print_field() {
    for (short i = 0; i < y; i++) {
        for (short j = 0; j < x; j++) {
            printf("%c ", coordinates[i][j]);
        }
        puts("");
    }
}

/* count the neighbor live cells */
int neighbor_check(int y, int x) {
    int neighbors_count = 0;
    // for (short i = y-1; i <= y+1; i++) {
    //     for (short j = x-1; j <= x+1; j++) {
    //         if (coordinates[i][j] == 'o') {
    //             neighbors_count++;
    //         }
    //     }
    // }
    if (coordinates[y-1][x-1] == 'o') {
        neighbors_count++;
    }
    if (coordinates[y-1][x] == 'o') {
        neighbors_count++;
    }
    if (coordinates[y-1][x+1] == 'o') {
        neighbors_count++;
    }
    if (coordinates[y][x-1] == 'o') {
        neighbors_count++;
    }
    if (coordinates[y][x+1] == 'o') {
        neighbors_count++;
    }
    if (coordinates[y+1][x-1] == 'o') {
        neighbors_count++;
    }
    if (coordinates[y+1][x] == 'o') {
        neighbors_count++;
    }
    if (coordinates[y+1][x+1] == 'o') {
        neighbors_count++;
    }
    return neighbors_count;
}

int main () {

    /* fill the field with dots */
    for (short i = 0; i < y; i++) {
        for (short j = 0; j < x; j++) {
            coordinates[i][j] = '.';
        }
    }

    /* set the seed */
    char a = coordinates[y/2][x/2-1] = 'o';
    char b = coordinates[y/2][x/2] = 'o';
    char c = coordinates[y/2][x/2+1] = 'o';

    print_field();

    int cell = neighbor_check(2, 3);
    printf("%i\n", cell);

    for (short i = 0; i < y; i++) {
        for (short j = 0; j < x; j++) {
            short z = neighbor_check(i, j);
            if (coordinates[i][j] == 'o' && (z <= 1 || z > 3)) {
                coordinates[i][j] = '.';
            } else if (coordinates[i][j] == '.' && z == 3) {
                coordinates[i][j] = 'o';
            }
        }
    }

    print_field();

    return 0;
}
