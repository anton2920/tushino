#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	int* a,*b,*c;
	int n1,n2,big,k=0,tmp;
	//создаем и заполняем массив а
	printf("Enter size of first array: ");
	do {
		scanf("%d", &n1);
		if (n1 < 1)
			printf("Input error.Try again: ");
	} while (n1< 1);
	a = (int*)malloc(n1  * sizeof(int));
	for (int i = 0; i < n1; i++)
	{
		printf("a[%d]= ", i);
		scanf("%d", (a + i));
	}
	//создаем и заполняем массив b
	printf("Enter size of second array: ");
	do {
		scanf("%d", &n2);
		if (n2 < 1)
			printf("Input error.Try again: ");
	} while (n2 < 1);
	b = (int*)malloc(n2 * sizeof(int));
	for (int i = 0; i < n2; i++)
	{
		printf("b[%d]= ", i);
		scanf("%d", (b + i));
	}
	printf("Before: \n");
	for (int i = 0; i < n1; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");
	for (int i = 0; i < n2; i++)
	{
		printf("%5d", b[i]);
	}
	printf("\n");
	//создаем и заполняем массив c
	
	c= (int*)malloc((n1+n2) * sizeof(int));
	for (int i = 0; i < (n1+n2); i++)
	{
		if(i<n1)
		c[i] = a[i];
		else
		{
			c[i] = b[k];
			k++;
		}
	}
	
	// сортируем массив с по возрастанию
	for (int i = 0; i < (n1 + n2); i++)
		for(int j=0;j<(n1+n2);j++)
	    {

			if (c[i] < c[j] && i>j)
			{
				tmp = c[i];
				c[i] = c[j];
				c[j] = tmp;
		    }
	    }
	printf("After:\n");
	// разделяем массивы с наибольшими и наименьшими элементами
	
	
		k = n2-1;
		for (int i = n1 + n2-1; i > n1-1; i--)
		{
			b[k] = c[i];
			k--;
		}
		c = (int*)realloc(c, n1 * sizeof(int));

		for (int i = 0; i < n2; i++)
		{
			printf("%5d", b[i]);
		}
		printf("\n");
		for (int i = 0; i < n1; i++)
		{
			printf("%5d", c[i]);
		}
	
	printf("\n");
	free(a);
	free(b);
	free(c);
	
	return 0;
}
