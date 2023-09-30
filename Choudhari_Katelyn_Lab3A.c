/*
COP3223 Summer 2023 Lab3A (A-E)
Copyright 2023 Choudhari Katelyn
*/

//Write a statement or a set of statements to accomplish each of the following tasks:

#include <stdio.h>
#include <math.h>
/*
int main(void) {
	
//a) Sum the odd integers between 1 and 99 using a for statement. Use the integer variables sum and count.
	int sum = 0;
	int count = 0;

	for (int i = 1; i <= 99; i+= 2) {
		sum = sum + i;
		count++;
	}
	
	printf("%d\n", sum);

//b) Print the value 333.546372 in a field width of 15 characters with precisions of 1, 2, 3, 4 and 5. Left - align the output. What are the five values that print?
	float num = 333.546372;

	printf("%-15.1f\n", num);
	printf("%-15.2f\n", num);
	printf("%-15.3f\n", num);
	printf("%-15.4f\n", num);
	printf("%-15.5f\n", num);

	/*The five values that print are :
	333.5
	333.55
	333.546
	333.5464
	333.54639*/
	
//c) Calculate the value of 2.5 raised to the power of 3 using the pow function. Print the result with a precision of 2 in a field width of 10 positions. What is the value that prints?
/*
double i;
	i = pow(2.5, 3);
	printf("%10.2f\n", i);

	/*The value that prints is 15.62*/

//d) Print the integers from 1 to 20 using a while loop and the counter variable x. Print only five integers per line. [Hint:Use the calculation x % 5. When this is 0, print a newline character, otherwise print a tab character.]
	/*
	int x = 1;
	while (x <= 20) {
		printf("%d", x);

		if (x % 5 == 0) {
			printf("\n");
		}
		else {
			printf("\t");
		}
		
		x++;
	}

//e) Repeat Exercise 4.3(d) using a for statement
	for (int x = 1; x <= 20; x++) {
		printf("%d", x);

		if (x % 5 == 0) {
			printf("\n");
		}
		else {
			printf("\t");
		}
	}

}
*/