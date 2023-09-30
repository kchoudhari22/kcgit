/*
COP3223 Summer 2023 Assignment 1.2
Copyright 2023 Choudhari Katelyn
*/

//A program that reads in a five digit integer and determines whether or not it’s a palindrome.
/*
#include <stdio.h>

int main(void) {

	//init variables
	int num;
	int remainder;
	int forwards;
	int backwards = 0;

	//get and read user input for five digit number
	printf("%s", "Please enter a five digit integer: ");
	scanf_s("%d", &num);

	//init new variable for comparision
	int new_num = num;

	//init loop that iterates through the number using
	//integer division and remainder operator to separate
	//the number into its individual digits
	while (num != 0) {
		remainder = (num % 10);
		backwards = (backwards * 10) + remainder;
		num = (num / 10);
	}

	//condition determines if five digit number is a palidrome or not
	//by comparing user input (forwards variable) to
	//backwards variable (num --> new_num after iterating
	//through each digit with while loop)
	if (new_num != backwards) {
		printf("%d is not a palindrome number.", new_num); //prints if not true
	}
	else {
		printf("%d is a palindrome number.", new_num); //prints if true
	}

}
*/