//2-D array is defined as array_name[row_index][column_index]

#include <stdio.h>

//int main(void) {
//	//define a 3x4 2D array, init each element to 0
//	int a[3][4] = { 0 };
//	int b[3][4] = { {1},{2},{3} };
//	for (int i = 0; i < 3; i++) {//3 rows
//		for (int j = 0; j < 4; j++) {//4 columns
//			printf("%4d", b[i][j]);
//		}
//	}
//}

//write a program to produce a multiplication table from 1 to 9 
// NOTES ARE NOT PRINTING GRID RIGHT***********
//int main(void) {
//	int mul_table[10][10] = { 0 }; //size of table
//
//	for (int i = 0; i < 10; i++) { //for rows
//		if (i == 0) {
//			for (int j = 0; j < 10; j++) {
//				mul_table[i][j] = j; //fills the first row
//			}
//		}
//		else {
//			for (int j = 0; j < 10; j++) {
//				//mul_table[i][j] = (j == 0 ? i : i * j);
//					if (j == 0) {
//						mul_table[i][j] = i;//fills the first column
//					}
//				else {
//					mul_table[i][j] = i * j;
//				}
//			}
//		}
//	}
//
//	for (int i = 0; i < 10; i++) {
//		for (int j = 0; j < 10; j++) {
//			printf("%4d", mul_table[i][j]);
//		}
//		printf("\n");
//	}
//}

//POINTERS ARE VARIABLES WHO VALUE ARE MEMORY ADDRESS
//int main(void) {
//	int a = 7;
//	int* aPtr = &a;//stores the value of a pName. p_name
//	printf("Address of a is %p\n", &a);
//	printf("Value of aPtr is %p\n", aPtr);
//	printf("Value of a is %d\n", a);
//	printf("Value of *aPtr is %d\n", *aPtr);
//	printf("&*aPtr = %p\n", &*aPtr);//the address of the variable a, value store in the pointer
//	printf("&aPtr = %p\n", *&aPtr);
//	printf("*&aPtr = %p\n", *&aPtr);
//
//	//MISSING COMMENT NOTES*********************
//
//	int* aPtr, b;//* does not distribute to each variable
//	int* bPtr = NULL; //equal to 0
//}

//int plusOne(int n);
//void plusOne_reference(int* nPtr);
//
//int main(void) {
//	int number = 5;
//	number = plusOne(number);//passing by value
//	printf("Number is %d\n", number);
//
//	plusOne_reference(&number);//passing by reference
//	printf("Number is %d\n", number);
//}
//
//int plusOne(int n) {
//	return n + 1;
//}
//
////actually modify number in the main
//void plusOne_reference(int* nPtr) {//recieves the address of an interger variable, stores the address in nPtr
//	*nPtr += 1;
//	//no return value
//}