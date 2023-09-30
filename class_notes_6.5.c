
#include <stdio.h>

//while versus do... while 
//while loop just checks the condition
//do.. while loop will do action then check the condition

//int main(void) {
	//int i = 0;

	//while (i < 6) {
	//	printf("%d", i);
	//	i++;
	//}

	//puts("");
	//do {
	//	printf("%d", i);
	//	i--;
	//} while (i > 0);

	//int i = 7;

	//while (i < 6) { //the action will execute only when the condition met
	//	printf("%s", "Using while loop\n");
	//	printf("%d", i);
	//	i++;
	//}

	//puts("");
	//do { //the action will execute at least once regardless of the condition
	//	printf("%s", "Using do... while loop\n");
	//	printf("%d", i);
	//	i++;
	//} while (i < 6);

	////break versus continue
	//for (int i = 0; i < 10; i++) {
	//	if (i == 6) {
	//		break; //will end the loop at 6 and print 12345
	//		//continue; //will skip 6 in this condition and print 12345789
	//	}
	//printf("%d ", i);
	//}
	//puts("\nJump out of the loop.");	
	//
	////logical operators
	////logic and &&     both conditions need to be true
	////logic or ||      if either condition is true
	////logic not !      


	////truth table
	////a     b   a && b     1 can be replaced with nonzero
	////0     0   0
	////1     0   0
	////0     1   0
	////1     1   1

	////0 = false
	////nonzero = true

	//int a = 0;
	//int b = 3;

	////and condition
	//if (a == 5 && b == 3) {
	//	puts("a = 5 b = 3");
	//}
	//else {
	//	puts("a != 5 or b != 3");
	//}

	////or condition
	//if (a == 5 || b == 3) {
	//	puts("a = 5 or b = 3");
	//}
	//else {
	//	puts("a != 5 or b != 3");
	//}

	////not condition
	////a     !a
	////1     0
	////0     1
	//if (a != 5) {
	//	puts("a != 5");
	//}
	//else {
	//	puts("a = 5");
	//}

	//practice examples
	//ask user for size and print out the pattern
	//if user enter 4, the patter is like below
	//*
	//**
	//***
	//****

	//use for loop
	//int row = 0;
	//printf("%s", "Enter the size of the pattern : ");
	//scanf_s("%d", &row);

	//for (int i = 1; i <= row; i++) { //control rows
	//	for (int j = 1; j <= i; j++) { //control column
	//		printf("%s", "*");
	//	}
	//	puts(" ");
	//}

	//printf("\n");

	//if user enter 4, the patter is like below
	//****
	//***
	//**
	//*

	//for (int i = row; i >= 0; i--) { //control rows
	//	for (int j = 1; j <= i; j++) { //control column
	//		printf("%s", "*");
	//	}
	//	puts(" ");
	//}

	////or you can do it as:
	//puts(" ");
	//for (int i = 0; i < row; i++) {
	//	for (int j = row; j > i; j--);
	//	printf("%s", "*");
	//}
	//puts(" ");


	//if user enter 4, the pattern is like
	//****
	//***
	//**
	//*

	//print *when column >=row, print space when column < row
//	printf("%s", "example 4");
//
//	puts(" ");
//	for (int i = 0; i < row; i++) { //control rows
//		for (int j = 0; j > i; j++) { //control column
//			printf("%s", " ");
//		}
//		for (int k = 0; k < row; k++) {
//			printf("%s", "*");
//		}
//		puts(" ");
//	}
//
//	//or you can do it as:
//
//	printf("%s", "example 5");
//
//	puts(" ");
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < row; j++) {
//			if (j > i) {
//				printf("%s", " ");
//			}
//			else {
//				printf("%s", "*");
//			}
//		}
//		puts(" ");
//	}
//
//}