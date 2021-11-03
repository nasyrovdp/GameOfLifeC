#include <stdio.h>
#include <unistd.h>

#define SIZE 30

int y = SIZE;
int x = SIZE;
char coordinates[SIZE][SIZE];
char coordinates_future[SIZE][SIZE];

void print_field() {
    /* print the whole field */
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%c ", coordinates[i][j]);
        }
        puts("");
    }
}

void fill_current_field() {
    /* fill the field with spaces */
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            coordinates[i][j] = ' ';
        }
    }
}

void fill_future_field() {
    /* fill the future field with spaces */
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            coordinates_future[i][j] = ' ';
        }
    }
}

int count_neighbors(int cell_y, int cell_x) {
    int neighbors_count = 0;
    for (int i = cell_y-1; i <= cell_y + 1; i++) {
        for (int j = cell_x-1; j <= cell_x + 1; j++) {
            if (coordinates[i][j] == 'o') {
                neighbors_count++;
            }
        }
    }
    if (coordinates[cell_y][cell_x] == 'o') {
        neighbors_count--;
    }
    return neighbors_count;
}

void make_move() {
    for (int i = 1; i < y; i++) {
        for (int j = 1; j < x; j++) {
            if (coordinates[i][j] == 'o' && (count_neighbors(i, j) < 2 || count_neighbors(i, j) > 3)) {
                coordinates_future[i][j] = ' ';
            } else if (coordinates[i][j] == ' ' && count_neighbors(i, j) == 3) {
                coordinates_future[i][j] = 'o';
            } else if (coordinates[i][j] == 'o' && (count_neighbors(i, j) == 2 || count_neighbors(i, j) == 3)) {
                coordinates_future[i][j] = 'o';
            }
        }
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            coordinates[i][j] = coordinates_future[i][j];
        }
    }
}

// int neighbor_check(int y, int x) {
//     /* count the neighbor live cells */
//     int neighbors_count = 0;
//     for (int i = y-1; i <= y+1; i++) {
//         for (int j = x-1; j <= x+1; j++) {
//             if (coordinates[i][j] == 'o') {
//                 neighbors_count++;
//             }
//         }
//     }
//     if (coordinates[y][x] == 'o') {
//         neighbors_count--;
//     }
//     return neighbors_count;
// }

int main () {
    fill_current_field();
    fill_future_field();

    /* set the seed */
    for (int i = -5; i <= 4; i++) {
        coordinates[y/2][x/2+i] = 'o';
    }

    print_field();
    usleep(1000000);

    // printf("%i\n", count_neighbors(1, 1));
    for (int i = 0; i < 50; i++) {
        make_move();
        printf("    step %i:\n", i + 1);
        print_field();

        usleep(300000);
    }

    return 0;
}
