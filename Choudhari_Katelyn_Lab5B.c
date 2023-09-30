/*
COP3223 Summer 2023 Lab5B
Copyright 2023 Choudhari Katelyn
*/

//A program that reads 20 numbers between 10 and 100, inclusive.
//Numbers are only printed if it’s not a duplicate of a number already read.

//#include <stdio.h>
//#define SIZE 20
//enum status { rep, not_rep };
//
//int main(void) {
//	//init array and variables
//	int arr [SIZE] = {0};
//	enum status status_t;
//	int num;
//	int counter = 0;
//
//	printf("%s","Enter 20 numbers between 10-100: \n");//gets user input
//	
//	//loop iterates through SIZE of array
//	for (int i = 0; i < SIZE; i++) {
//		scanf_s("%d", &num);//reads user input
//
//		//checks user numbers are between 10-100
//		//if not, asks user again and continues
//		//decrements counter if number is out of range
//		if (num < 10 || num > 100) {
//			printf("%s", "Only enter numbers 10-100:\n");
//			i--;
//			continue;
//		}
//		//breaks if repeated numbers are found
//		status_t = not_rep;
//		for (int j = 0; j < counter; j++) {
//			if (arr[j] == num) {
//				status_t = rep;
//				break;
//			}
//		}
//		//unrepeated numbers are stored in array
//		if (status_t == not_rep) {
//			arr[counter] = num;
//			counter++;
//		}
//	}
//	//prints non-repeated numbers
//	puts("List of user numbers without repeated numbers: ");
//	for (int i = 0; i < counter; i++) {
//		printf("%d ", arr[i]);
//	}
//}