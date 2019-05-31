#include <stdio.h>

#define NAME (100)

struct arr {
    int a[NAME][NAME];
    int m; /* Rows */
    int n; /* Columns */
};

void mas_read(struct arr *);
int max_find(struct arr *);

main() {

    /* Initializing variables */
    struct arr mas;
    int max_line = 0;

    /* I/O flow */
    mas_read(&mas);

    /* Main part */
    max_line = max_find(&mas);

    /* Final output */
    printf("The latest number of line with even numbers only: %d\n", max_line);

}

void mas_read(struct arr *mas) {

    /* Initializing variables */
    int i, j;

    /* I/O flow */
    do {
        printf("Type the number of rows: ");
        scanf("%d", &mas->m);
    } while (mas->m <= 0 || mas->m > NAME);

    do {
        printf("Type the number columns: ");
        scanf("%d", &mas->n);
    } while (mas->n <= 0 || mas->n > NAME);

    for (i = 0; i < mas->m; ++i) {
        for (j = 0; j < mas->n; ++j) {
            printf("Type %d%s element in %d%s row: ", j, (j == 1) ? "st" : (j == 2) ? "nd" : (j == 3) ? "rd" : "th", i, (i == 1) ? "st" : (i == 2) ? "nd" : (i == 3) ? "rd" : "th");
            scanf("%d", &mas->a[i][j]);
        }
    }
}

int max_find(struct arr *mas) {

    /* Initializing variables */
    int i, j, flag = 1, latest = 0;

    /* Main part */
    for (i = 0; i < mas->m; ++i) {
        for (j = 0;j < mas->n; ++j) {
            if (mas->a[i][j] % 2) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            latest = i;
        }
        flag = 1;
    }

    /* Returning value */
    return latest;
}
