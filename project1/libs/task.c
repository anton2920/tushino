#include "../headers/head.h"

void task(int *a, int n) {

	int i, max = *a, min = *a;

	max_min(&max, &min, a, n);

	for (i = 0; i < n; i++){
		if (a[i] == min) 
			a[i] = max;
		else if (a[i] == max) 
			a[i] = min;
}	
}
void max_min(int *max, int *min, const int *x, int n) {

	int i;

	for (i = 1; i < n; i++){
		if (x[i] > *max) 
			*max = x[i];
		if (x[i] < *min) 
			*min = x[i];
	}
}
