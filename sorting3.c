//Dr. Andrew Steinberg
//COP3502 Computer Science 1
//Qucksort Algorithm

#include <stdio.h>
#include <stdlib.h>

void quickSort(int * arr, int p, int r);
int partition(int * arr, int p, int r);
void partitionSample(int * arr, int p, int r);

int main(void)
{
	
	int example[8] = {3, 8, 9, 11, 1, 6, 4, 7};
	printf("------------------------------------------------------------------------\n");
	printf("Sample Partition Example\n");
	printf("Before Partition\n");
	
	for(int x = 0; x < 8; ++x)
		printf("%4d", example[x]);
	printf("\n");
	partitionSample(example, 0, 7);
	
	printf("After Partition\n");
	for(int x = 0; x < 8; ++x)
		printf("%4d", example[x]);
	printf("\n");
	
	
	int arr[10];
	
	for(int x = 0; x < 10; ++x)
		arr[x] = rand() % 80;
	
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	printf("Before Quicksort\n");
	
	for(int x = 0; x < 10; ++x)
		printf("%4d", arr[x]);
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	
	quickSort(arr, 0,  sizeof(arr)/sizeof(arr[0]) - 1);
	
	printf("After Quicksort\n");
	
	for(int x = 0; x < 10; ++x)
		printf("%4d", arr[x]);
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	
	return 0;
}

void quickSort(int * arr, int p, int r) 
{
	if (p < r) 
	{  
		int q = partition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
}

int partition(int * arr, int p, int r) 
{
	int x = arr[r]; //random pivot

	int i = (p - 1);

	for (int j = p; j < r; j++) 
	{
		if (arr[j] <= x) 
		{
			++i;
	  
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}	
	}
  
	int temp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = temp;
  
	return (i + 1);
}

void partitionSample(int * arr, int p, int r) 
{
	int x = arr[r]; //pivot

	int i = (p - 1);

	for (int j = p; j < r; j++) 
	{
		printf("is %d smaller than or equal to %d\n", arr[j], x);
		
		if (arr[j] <= x) 
		{
			printf("yes\n");
			++i;
			
			printf("Swap arr[%d] = %d and arr[%d] = %d with each other\n", i, arr[i], j, arr[j]);
	  
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else
		{
			printf("no\n");
		}
	}
	
	
	printf("Swap arr[%d] = %d and arr[%d] = %d with each other\n", i + 1, arr[i + 1], r, arr[r]);
	int temp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = temp;
}
