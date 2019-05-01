#include <stdio.h>
#include <stdlib.h>

#define MAX(A, B) (((A) > (B)) ? (A) : (B))

/* Function's declarations */
int knapsack(int **, int, int, const int *, const int *);
void items_in_optimal(int **t, int, int, const int *, const int *);

/* Function's definitions */
main() {

    /* Initializing variables */
    int *val = NULL, *wt = NULL, **cost = NULL;
    int m = 0, W = 0, i, max_val = 0;

    /* I/O flow */
    do {
        printf("Type the number of items: ");
        scanf("%d", &m);
    } while (m <= 0);

    do {
        printf("Type bag's capacity: ");
        scanf("%d", &W);
    } while (W <= 0 || W > 50);

    if ((val = (int *) malloc((m + 1) * sizeof(int))) == NULL || (wt = (int *) malloc((m + 1) * sizeof(int))) == NULL ||
            (cost = (int **) malloc((m + 1) * sizeof(int *))) == NULL) {
        fprintf(stderr, "Error! Couldn't allocate memory!");
        return -1;
    }

    for (i = 0; i <= m; ++i) {
        *(cost + i) = (int *) malloc((W + 1) * sizeof(int));
    }

    printf("\n");

    for (i = 1; i <= m; ++i) {
        do {
            printf("Type the weight of %d%s item: ", i, (i == 1) ? "st" : (i == 2) ? "nd" : (i == 3) ? "rd" : "th");
            scanf("%d", (wt + i));
        } while (*(wt + i) <= 0);

        do {
            printf("Type the price of %d%s item: ", i, (i == 1) ? "st" : (i == 2) ? "nd" : (i == 3) ? "rd" : "th");
            scanf("%d", (val + i));
        } while (*(val + i) <= 0);

        printf("\n");
    }


    /* Main part */
    max_val = knapsack(cost, m, W, wt, val);
    printf("\nYou should take items {weight, cost}: ");
    items_in_optimal(cost, m, W, wt, val);
    printf("that will give you cost equals to %d\n", max_val);

    free(val);
    free(wt);
    for (i = 0; i <= m; ++i) {
        free(*(cost + i));
    }
    free(cost);
}

int knapsack(int **cost, int n, int W, const int *wm, const int *vm) {

    /* Initializing variables */
    int w, i;

    /* Main part */
    for (w = 0; w <= W; ++w) {
        cost[0][w] = 0;
    }

    for (i = 0; i <= n; ++i) {
        cost[i][0] = 0;
    }

    for (i = 1; i <= n; ++i) {
        for (w = 1; w <= W; ++w) {
            if (wm[i] > w) {
                cost[i][w] = cost[i - 1][w];
            } else {
                if (vm[i] + cost[i - 1][w - wm[i]] > cost[i - 1][w]) {
                    cost[i][w] = vm[i] + cost[i - 1][w - wm[i]];
                } else {
                    cost[i][w] = cost[i - 1][w];
                }
            }
        }
    }

    /* Returning value */
    return cost[n][W];
}

void items_in_optimal(int **cost, int n, int W, const int *wm, const int *vm) {

    /* Initializing variables */
    int i = n;
    int j = W;

    /* Main part */
    while (i && j) {
        if (cost[i][j] != cost[i - 1][j]) {
            printf("{%d, %d}, ", *(wm + i), *(vm + i));
            j -= wm[i];
        }
        --i;
    }
}