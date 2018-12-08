#include "../headers/head.h"

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void read_rand(int *arr, const int *length)
{
	int range_min, range_max, i;

	printf("Enter lower bound: ");
	scanf("%d", &range_min);

	printf("Enter upper bound: ");
	scanf("%d", &range_max);

	if (range_min > range_max)
		swap(&range_min, &range_max);

	for (i = 0; i < *length; ++i)
		arr[i] = rand_number(range_min, range_max);
}

int rand_number(int range_min, int range_max)
{
	return rand() % (range_max - range_min + 1) + range_min;
}

void read_bfile(int *arr, const int *length)
{
	char name[100];
	int i;
	printf("Enter name of the file: ");
	scanf("%s", name);

	FILE* input = NULL;
	input = fopen(name, "rb");

	if (input != NULL)
	{
		fseek(input, 0, SEEK_SET);
		for (i = 0; i < *length; ++i)
		{
			fread(&arr[i], sizeof(int), 1, input);
		}
		fclose(input);
	}
	printf("File could not be open.\n");
}

void write_bfile(const int *arr, const int *length)
{
	char name[100];
	int i;
	printf("Enter name of the file: ");
	scanf("%s", name);

	FILE* output = NULL;
	output = fopen(name, "wb");

	if (output != NULL)
	{
		for (i = 0; i < *length; ++i)
		{
			fwrite(&arr[i], sizeof(int), 1, output);
		}
		fclose(output);
	}
	else
		printf("File could not be open.\n");

}

void read_file(int *arr, const int *length)
{
	char name[100];
	int i;
	printf("Enter name of the file: ");
	scanf("%s", name);

	FILE* file = NULL;
	file = fopen(name, "r");

	if (file != NULL)
	{
		for (i = 0; i < *length; ++i)
		{
			fscanf(file, "%d", &arr[i]);
			printf("%d", arr[i]);
		}
		fclose(file);
	}
	else
		printf("File could not be open.\n");
}

void write_file(const int *arr, const int *length)
{
	char name[100];
	int i;
	printf("Enter name of the file: ");
	scanf("%s", name);

	FILE* file = NULL;
	file = fopen(name, "w");

	if (file != NULL)
	{
		for (i = 0; i < *length; ++i)
		{
			fprintf(file, "%d", arr[i]);
			printf("%d", arr[i]);
		}
		fclose(file);
	}
	else
		printf("File could not be open.\n");
}

void read_key(int *mas, const int *n) {

	/* Initializing variables */
    int i;

    /* Main part */
    for (i = 0; i < *n; ++i) {
        printf("| Type %d%s element: ", i, (i == 1) ? "st" : (i == 2) ? "nd" : (i == 3) ? "rd" : "th");
        scanf("%d", mas + i);
    }
}

void write_scr(const int *mas, const int *n) {

    /* Initializing variables */
    int i;

    /* I/O flow */
    for (i = 0; i < *n; ++i) {
        printf("%d ", *(mas + i));
    }

    /* Final output */
    printf("\n");
}