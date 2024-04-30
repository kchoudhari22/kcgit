//Dr. Andrew Steinberg
//COP3502 Computer Science 1
//Quadratic Sorting Algorithms
#include <stdio.h>
#include <stdlib.h>


void bubblesort(int * arr, int n);
void insertionSort(int * arr, int size);
void selectionSort(int * arr, int size);

int main(void)
{
	int arr[10];
	
	for(int x = 0; x < 10; ++x)
		arr[x] = rand() % 80;
	
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	printf("Before Bubble Sort\n");
	
	for(int x = 0; x < 10; ++x)
		printf("%4d", arr[x]);
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	
	bubblesort(arr, sizeof(arr)/sizeof(arr[0]));
	
	printf("After Bubble Sort\n");
	
	for(int x = 0; x < 10; ++x)
		printf("%4d", arr[x]);
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	
	for(int x = 0; x < 10; ++x)
		arr[x] = rand() % 80;
	
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	printf("Before Insertion Sort\n");
	
	for(int x = 0; x < 10; ++x)
		printf("%4d", arr[x]);
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	
	insertionSort(arr, sizeof(arr)/sizeof(arr[0]));
	
	printf("After Insertion Sort\n");
	
	for(int x = 0; x < 10; ++x)
		printf("%4d", arr[x]);
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");

	
	for(int x = 0; x < 10; ++x)
		arr[x] = rand() % 80;
	
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	printf("Before Selection Sort\n");
	
	for(int x = 0; x < 10; ++x)
		printf("%4d", arr[x]);
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	
	selectionSort(arr, sizeof(arr)/sizeof(arr[0]));
	
	printf("After Selection Sort\n");
	
	for(int x = 0; x < 10; ++x)
		printf("%4d", arr[x]);
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");

	
	return 0;
}

void bubblesort(int * arr, int n)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n - i - 1; ++j)
			if(arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	}
}


void insertionSort(int * arr, int n)
{
	for (int i = 1; i < n; ++i)
	{
		int card = arr[i];
		
		//insert into the sorted sequence
		
		int j = i - 1;
		
		while(j >= 0 && arr[j] > card)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		
		arr[j + 1] = card;
	}
}

void selectionSort(int * arr, int n)
{
	for(int i = 0; i < n; ++i)
	{
		int min = i;
		
		for(int j = i + 1; j < n; ++j)
			if(arr[j] < arr[min])
				min = j;
					
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

