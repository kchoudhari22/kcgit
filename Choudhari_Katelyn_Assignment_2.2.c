/*
COP3223 Summer 2023 Assignment 2.2
Copyright 2023 Choudhari Katelyn
*/

//A program that calculates the greatest common divisor of two integers

//#include <stdio.h>
//
//int gcd(int x, int y);//function prototype
//
//int main(void) {
//	//init variables
//	int x = 0;
//	int y = 0;
//	printf("%s", "Please input the first number: ");//get user input
//	scanf_s("%d", &x);//read user input
//	printf("%s", "Please input the first number: ");
//	scanf_s("%d", &y);
//
//	int divisor = gcd(x, y);//call fnct gcd and set its return value to variable divisor
//	printf("The greatest common divisor for %d and %d is %d", x, y, divisor);
//}
//
//int gcd(int x, int y) {//fnct header
//	if (y == 0) {//checks if y is equal to zero than
//		//x is the gcd and returns the x value
//		return x;
//	}
//	else {//recursion, calls y value until it becomes 0
//		//and calculates and returns gcd
//		return gcd(y, x % y);
//	}
//}