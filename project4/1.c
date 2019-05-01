#include <stdio.h>
#include <stdlib.h>

#define GREATER (-1)
#define LESS (1)
#define EQUAL (0)

struct time {
    int h;
    int m;
    int s;
};

int time_cmp(const struct time *, const struct time *);

main() {

    /* Initializing variables */
    struct time *t;
    FILE *fp;
    int n, i;

    if ((fp = fopen("1.txt", "r")) == NULL) {
        fprintf(stderr, "Error! Couldn't open file!\n");
        return -1;
    }

    fscanf(fp, "%d", &n);
    if (n <= 0) {
        printf("Error! Wrong number of time records!\n");
    }

    if ((t = (struct time *) malloc(n * sizeof(struct time))) == NULL) {
        fprintf(stderr, "Error! Couldn't allocate memory!\n");
        return -1;
    }

    for (i = 0; i < n; ++i) {
        fscanf(fp, "%d:%d:%d", &(t + i)->h, &(t + i)->m, &(t + i)->s);
    }

    fclose(fp);

    printf("Source array: \n");

    for (i = 0; i < n; ++i) {
        printf("%d:%d:%d\n", (t + i)->h, (t + i)->m, (t + i)->s);
    }

    qsort((void **) t, n, sizeof(struct time), (int (*)(const void *, const void *)) time_cmp);

    if ((fp = fopen("1.txt", "w")) == NULL) {
        fprintf(stderr, "Error! Couldn't open file!\n");
        return -1;
    }

    printf("\nResult: \n");
    for (i = 0; i < n; ++i) {
        printf("%d:%d:%d\n", (t + i)->h, (t + i)->m, (t + i)->s);
        fprintf(fp, "%d:%d:%d\n", (t + i)->h, (t + i)->m, (t + i)->s);
    }

    fclose(fp);
}

int time_cmp(const struct time *a, const struct time *b) {

    /* Initializing variables */
    struct time temp = { a->h - b->h, a->m - b->m, a->s - b->s};

    /* Main part */
    if (temp.h > 0) {
        return GREATER;
    } else if (temp.h < 0) {
        return LESS;
    } else {
        if (temp.m > 0) {
            return GREATER;
        } else if (temp.m < 0) {
            return LESS;
        } else {
            if (temp.s > 0) {
                return GREATER;
            } else if (temp.s < 0) {
                return LESS;
            } else {
                return EQUAL;
            }
        }
    }
}