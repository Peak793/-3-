#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
void bubblesort(int*p,int n)     // sort the line number
{
	int temp;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - i - 1 ; j++)
		{
			if (*(p + j) > * (p + j + 1))
			{
				temp = *(p +j+1);
				*(p + j+1) = *(p + j);
				*(p + j) = temp;
			}
		}
	}
}
int main()
{
	int* x,* a;
	int n,max=0;
	scanf("%d", &n);//get the input of all looblike
	if (n < 2 || n > 1000)
	{
		end :
		printf("\n---------Error---------\n");
		return 0;
	}
	a = (int*)malloc(n * sizeof(int));
	x = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)       //get the input of loopliked line
	{
		scanf("%d", (x + i));
		if (*(x + i) <=0 || *(x + i) > 10000)
		{
			goto end;
		}
	}
	bubblesort(x, n);// sort the line from low to high
	for (int i = 0; i < n; i++) // find the freqentcy of each line
	{
		*(a + i) = 0;
		for (int j = 0; j < n; j++)
		{
			if (*(x + i) == *(x + j) && *(x+i)!=*(x+i-1))
			{
				*(a + i)= *(a+i)+1;
			}
		}
	}
	for (int i = 0; i < n; i++)//find the most loobliked line
	{
		if (max<*(a+i))
		{
			max = *(a + i);
		}
	}
	for (int i = 0; i < n; i++)//get rid of the freqentcy that is not equal to max;
	{
		if (max != *(a + i))
		{
			*(a + i) = 0;
		}
	}
	for (int i = 0; i < n; i++) //print all of line numbers that were loobliked the most
	{
		if (*(a + i) != 0)
		{
			printf("%d ", *(x + i));
		}
	}
	return 0;
}