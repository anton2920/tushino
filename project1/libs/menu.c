#include "../headers/head.h"

int menu()
{
    int f;
    printf("----------Input type----------\n"
           "1.From the keyboard\n"
           "2.From text file\n"
           "3.From binary file\n"
           "4.Random input\n");
    do
    {
        scanf("%d",&f);
    }while(f < 0 || f > 5);

    return f;
}
int menu2()
{
    int f;
    printf("----------Output type----------\n"
           "1.On the screen\n"
           "2.In the text file\n"
           "3.In the binary file\n");
    do{
        scanf("%d",&f);
    }while(f < 0 || f > 4);


    return f;
}
int menu3()
{
    int f;
    printf("You want to try again?\n"
           "Print 0 if don't want again, or 1 if you want\n");
    do
    {
        scanf("%d",&f);
    }while(f < 0 || f > 2);

    return f;
}
int num_elem(void)
{
	int n;
	do
	{	
		printf("Enter the number of elements\n");
		scanf("%d",&n);
	}while(n < 0 || n > 1024);
	
	return n;
}


