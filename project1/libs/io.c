#include "../headers/head.h"

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void fill_random(int *arr, const int length)
{
	int range_min, range_max, i;

	printf("Enter lower bound: ");
	scanf("%d", &range_min);

	printf("Enter upper bound: ");
	scanf("%d", &range_max);

	if (range_min > range_max)
		swap(&range_min, &range_max);

	for (i = 0; i < length; ++i)
		arr[i] = rand_number(range_min, range_max);
}

int rand_number(int range_min, int range_max)
{
	srand((unsigned)time(NULL));
	return rand() % (range_max - range_min + 1) + range_min;
}

void read_from_bin(int *arr, const int length)
{
	char name[100];
	printf("Enter name of the file: ");
	scanf("%s", &name);

	FILE* input = NULL;
	input = fopen(name, "rb");

	if (input != NULL)
	{
		fseek(input, 0, SEEK_SET);
		for (int i = 0; i < length; ++i)
		{
			fread(&arr[i], sizeof(int), 1, input);
		}
		fclose(input);
	}
	printf("File could not be open.\n");
}

void print_to_bin(int *arr, const int length)
{
	char name[100];
	printf("Enter name of the file: ");
	scanf("%s", &name);

	FILE* output = NULL;
	output = fopen(name, "w+b");
	int num;

	if (output != NULL)
	{
		for (int i = 0; i < length; ++i)
		{
			fwrite(&arr[i], sizeof(int), 1, output);
		}
		fclose(output);
	}
	else
		printf("File could not be open.\n");

}

void read_from_txt(int *arr, const int length)
{
	char name[100];
	printf("Enter name of the file: ");
	scanf("%s", &name);

	FILE* file = NULL;
	int size;
	file = fopen(name, "r");
	if (file != NULL)
	{
		fscanf(file, "%d", &size);

		for (int i = 0; i < size; ++i)
		{
			fscanf(file, "%d", &arr[i]);
			printf("%d", arr[i]);
		}
		fclose(file);
	}
	else
		printf("File could not be open.\n");
}

void print_to_txt(int *arr, const int length)
{
	char name[100];
	printf("Enter name of the file: ");
	scanf("%s", &name);

	FILE* file = NULL;
	int size;
	file = fopen(name, "w+");

	if (file != NULL)
	{
		for (int i = 0; i < length; ++i)
		{
			fprintf(file, "%d", &arr[i]);
			printf("%d", arr[i]);
		}
		fclose(file);
	}
	else
		printf("File could not be open.\n");
}