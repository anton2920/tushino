#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const int n = 10;
const int m = 15;

struct person
{
	char first_name[30];
	char last_name[30];
	int judge_s_seat[10];
	int award;
	int mark[10];
};

void end(person man[], int size_man, int size_j)
{
	printf("\n");
	for (int i = 0; i < size_man; i++)
	{
		printf("| Skater: %s %s; Prize place %d \n", man[i].first_name, man[i].last_name, man[i].award);
	}
}
void sorting_end(person man[], int size_man, int size_j)
{
	int sum[10] = {}, min = 99, prize = 0;

	for (int i = 0; i < size_man; i++)
	{	
		for (int j = 0; j < size_j; j++)
		{
			sum[i] += man[i].judge_s_seat[j];
		}
	}

	while (prize !=10)
	{
		prize++;
		for (int i = 0; i < size_man; i++)
		{
			if (min >= sum[i])
			{
				min = sum[i];
			}
		}
		for (int i = 0; i < size_man; i++)
		{
			if (min == sum[i])
			{
				man[i].award = prize;
				sum[i] = 100;
			}
		}
		min = 99;
	}
}
void sorting_by_judges(person man[], int size_man, int size_j)
{
	int sum_mark[7] = {};

	for (int j = 0; j < size_j; j++)
	{
		for (int k = 0; k < 7; k++)
		{
			sum_mark[k] = 0;
		}
		for (int i = 0; i < size_man; i++)
		{
			switch (man[i].mark[j])
			{
			case 0: {
				sum_mark[0]++;
				man[i].judge_s_seat[j] = 7;
			}break;
			case 1: {
				sum_mark[1]++;
				man[i].judge_s_seat[j] = 6;
			}break;
			case 2: {
				sum_mark[2]++;
				man[i].judge_s_seat[j] = 5;
			}break;
			case 3: {
				sum_mark[3]++;
				man[i].judge_s_seat[j] = 4;
			}break;
			case 4: {
				sum_mark[4]++;
				man[i].judge_s_seat[j] = 3;
			}break;
			case 5: {
				sum_mark[5]++;
				man[i].judge_s_seat[j] = 2;
			}break;
			case 6: {
				sum_mark[6]++;
				man[i].judge_s_seat[j] = 1;
			}break;
			
			}
		}
		if (sum_mark[6] == 0)
		{
			for (int i = 0; i < size_man; i++)
			{
				man[i].judge_s_seat[j]--;
			}
		}
		if (sum_mark[5] == 0)
		{
			for (int i = 0; i < size_man; i++)
			{
				if (man[i].judge_s_seat[j] != 1)
					man[i].judge_s_seat[j]--;
			}
		}
		if (sum_mark[4] == 0)
		{
			for (int i = 0; i < size_man; i++)
			{
				if (man[i].judge_s_seat[j] >= 2)
					man[i].judge_s_seat[j]--;
			}
		}
		if (sum_mark[3] == 0)
		{
			for (int i = 0; i < size_man; i++)
			{
				if (man[i].judge_s_seat[j] >= 3)
					man[i].judge_s_seat[j]--;
			}
		}
		if (sum_mark[2] == 0)
		{
			for (int i = 0; i < size_man; i++)
			{
				if (man[i].judge_s_seat[j] >= 4)
					man[i].judge_s_seat[j]--;
			}
		}
		if (sum_mark[1] == 0)
		{
			for (int i = 0; i < size_man; i++)
			{
				if (man[i].judge_s_seat[j] >= 5)
					man[i].judge_s_seat[j]--;
			}
		}
		if (sum_mark[0] == 0)
		{
			for (int i = 0; i < size_man; i++)
			{
				if (man[i].judge_s_seat[j] >= 6)
					man[i].judge_s_seat[j]--;
			}
		}
	}
}
void read_skater(person man[], int *size_man, int *size_j)
{
	do {
		printf("| Enter the number of skaters: ");
		scanf("%d", size_man);
	} while ((*size_man > 15) || (*size_man < 1));
	
	do {
		printf("| Enter the number of judges: ");
		scanf("%d", size_j);
	} while ((*size_j > 10) || (*size_j < 1));

	for (int i = 0; i < *size_man; i++)
	{
		printf("\n| Skater number %d \n", i+1);
		printf("| The name: ");
		scanf("%s", man[i].first_name);
		printf("| The last name: ");
		scanf("%s", man[i].last_name);
		for (int j = 0; j < *size_j; j++)
		{
			do {
				printf("| Evaluation of the %d judge: ", j+1);
				scanf("%d", &man[i].mark[j]);
			} while ((man[i].mark[j] > 6) || (man[i].mark[j] < 0));
			man[i].judge_s_seat[j] = 0;
		}
	}
}

int main()
{
	person man[15];
	int number_of_judges, size_man, size_j, sign;
	do {
		read_skater(man, &size_man, &size_j);
		sorting_by_judges(man, size_man, size_j);
		sorting_end(man, size_man, size_j);
		end(man, size_man, size_j);

		printf("| Try again?\n| Yes - 1\n| No - 0");
		do { 
			printf("\n| Answer: ");
			scanf("%d", &sign); 
		} while ((sign < 0) || (sign > 1));
	} while (sign != 0);
	
	return 0;
}
