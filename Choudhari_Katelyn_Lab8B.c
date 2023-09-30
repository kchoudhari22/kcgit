/*
COP3223 Summer 2023 Lab8B
Copyright 2023 Choudhari Katelyn
*/

//#include <stdio.h>
//#include <stdlib.h>
//
//int search(int* array, int size, int searchNum);
//int* expandSize(int* array, int* size);
//void displayArray(int* array, int size);
//
//int main(void){
//	//store number in dynamic array and initialize array to size 4
//	int length = 4;
//	int* array = (int*)malloc(length * sizeof(int));
//
//	int counter = 0;
//
//	//get user numbers
//	int userNum = 0;
//	while (1) {
//		printf("Enter a number: ");
//		scanf_s("%d", &userNum);
//		if (userNum == -1) {
//			break;
//		}
//		
//		if (counter == length) {
//			length *= 2;
//			array = expandSize(array, length);
//		}
//		array[counter] = userNum;
//		counter++;
//	}
//
//	displayArray(array, counter);
//
//	printf("Enter a number and I will search it in the array: ");
//	scanf_s("%d", &userNum);
//	int index =	search(array, counter, userNum);
//	if (index == -1) {
//		printf("Number not found.");
//	}
//	else {
//		printf("Number found at %d", index);
//	}
//}
//
//int search(int* array, int size, int searchNum) {
//	//search for the given number inside the array
//	//return the index of that number if it is in the array
//	//if not in the array return -1
//	for (int i = 0; i < size; i++) {
//		if (searchNum == array[i]) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//int* expandSize(int* array, int size) {
//	//double the size of the array when the size reaches the limit
//	int* Ptr = (int*)realloc(array, (size) * sizeof(int));
//	if (Ptr != NULL) {
//		return Ptr;
//	}
//	else {
//		printf("Allocation failed.");
//		exit (1);
//	}
//}
//
//void displayArray(int* array, int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%4d", array[i]);
//	}
//	puts("");
//}