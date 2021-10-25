#include <stdio.h>

int main() {
    int i;
    int j;

    printf(" ");
    for(i = 0; i < 30; i++) {
        printf("-");
    }
    puts("");

    for(j = 0; j < 30; j++) {
        printf("|");
        for(i = 0; i < 30; i++) {
            printf(" ");
        }
        printf("|");
        puts("");
    }

    printf(" ");
    for(i = 0; i < 30; i++) {
        printf("-");
    }
    puts("");
    
    return 0;
}
