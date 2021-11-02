#include <stdio.h>
#include <unistd.h>

#define SIZE 30

int y = SIZE;
int x = SIZE;
char coordinates[SIZE][SIZE];
char coordinates_future[SIZE][SIZE];

void print_field() {
    /* print the whole field */
    for (short i = 0; i < y; i++) {
        for (short j = 0; j < x; j++) {
            printf("%c ", coordinates[i][j]);
        }
        puts("");
    }
}

void fill_current_field() {
    /* fill the field with dots */
    for (short i = 0; i < y; i++) {
        for (short j = 0; j < x; j++) {
            coordinates[i][j] = ' ';
        }
    }
}

void fill_future_field() {
    /* fill the future field with dots */
    for (short i = 0; i < y; i++) {
        for (short j = 0; j < x; j++) {
            coordinates_future[i][j] = ' ';
        }
    }
}

int neighbor_check(int y, int x) {
    /* count the neighbor live cells */
    int neighbors_count = 0;
    for (short i = y-1; i <= y+1; i++) {
        for (short j = x-1; j <= x+1; j++) {
            if (coordinates[i][j] == 'o') {
                neighbors_count++;
            }
        }
    }
    if (coordinates[y][x] == 'o') {
        neighbors_count--;
    }
    return neighbors_count;
}

int main () {

    fill_current_field();
    fill_future_field();

    /* set the seed */
    for (int i = -5; i <= 4; i++) {
        coordinates[y/2][x/2+i] = 'o';
    }

    print_field();

    for (short i = 0; i < 50; i++) {

        /* check the whole field for future changes */
        for (short i = 0; i < y; i++) {
            for (short j = 0; j < x; j++) {
                short z = neighbor_check(i, j);
                if (coordinates[i][j] == 'o' && (z < 2 || z > 3)) {
                    coordinates_future[i][j] = ' ';
                } else if (coordinates[i][j] == 'o' && (z == 2 || z == 3)) {
                    coordinates_future[i][j] = 'o';
                } else if (coordinates[i][j] == ' ' && z == 3) {
                    coordinates_future[i][j] = 'o';
                }
            }
        }

        /* apply the changes to current field */
        for (short i = 0; i < y; i++) {
            for (short j = 0; j < x; j++) {
                coordinates[i][j] = coordinates_future[i][j];
            }
        }

        usleep(500000);

        puts("");
        printf("    step %i\n", i + 1);
        print_field();
    }

    return 0;
}
