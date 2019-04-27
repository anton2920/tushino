#include<stdio.h>
#include<malloc.h>


int main()
{
	int n, i, j;
	int *a, p;
	
	printf("Enter the size of array: ");
	scanf("%d",&n);
	
	
	a = (int *) malloc(n * sizeof(int));
	
	printf("Enter the array(1 - red, 2 - white, 3 - blue): ");
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n--------------------------------------------------------\n\n");
	
	printf("Source array: ");
	for(i = 0; i < n; i++)
	{
		switch(a[i])
		{
			case 1: printf(" red "); break;
			case 2: printf(" white "); break;
			case 3: printf(" blue "); break;
		}
	}
	printf("\n\n");
	
	printf("Result: ");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n - 1; j++)
		{
			if(a[j] > a[j+1])
			{
				p = a[j];
				a[j] = a[j+1];
				a[j+1] = p;
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		switch(a[i])
		{
			case 1: printf(" red "); break;
			case 2: printf(" white "); break;
			case 3: printf(" blue "); break;
		}
	}
	
}
