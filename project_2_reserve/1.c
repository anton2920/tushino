#include <stdio.h>

#define NAME (100)

struct arr {
    double a[NAME][NAME];
    int m;
};

void mas_read(struct arr *);

main() {

    /* Initializing variables */
    struct arr mas;
    int i, j, new_order, new_border = 0;

    /* I/O flow && VarCheck*/
    mas_read(&mas);

    /* Main part */
    i = 0;
    j = 0;
    new_order = mas.m - 1;
    while (i != (mas.m / 2) && j != (mas.m / 2)) {
        while (i < new_order) {
            printf("%.2lf ", mas.a[i][j]);
            ++i;
        }
        while (j < new_order) {
            printf("%.2lf ", mas.a[i][j]);
            ++j;
        }
        while (i > new_border) {
            printf("%.2lf ", mas.a[i][j]);
            --i;
        }
        while (j > new_border) {
            printf("%.2lf ", mas.a[i][j]);
            --j;
        }
        ++j;
        ++i;
        ++new_border;
        --new_order;
    }

    printf("%.2lf", mas.a[mas.m / 2][mas.m / 2]);

    /* Final output */
    printf("\n");
}

void mas_read(struct arr *mas) {

    /* Initializing variables */
    int i, j;

    /* I/O flow */
    for ( ; ; ) {
        printf("Type matrix order: ");
        scanf("%d", &mas->m);
        if (!(mas->m % 2)) {
            printf("Error! Order must be an odd number\n");
			continue;
        }
		if (mas->m >= NAME) {
			printf("Error! Can't handle more than 100 elements!\n");
			continue;
		} else {
			break;
		}
    }	
    for (i = 0; i < mas->m; ++i) {
        for (j = 0; j < mas->m; ++j) {
            printf("Type %d%s element in %d%s row: ", j, (j == 1) ? "st" : (j == 2) ? "nd" : (j == 3) ? "rd" : "th", i, (i == 1) ? "st" : (i == 2) ? "nd" : (i == 3) ? "rd" : "th");
            scanf("%lf", &mas->a[i][j]);
        }
    }
}
