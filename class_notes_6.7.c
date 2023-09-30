//divide and conquer
//standard library fuct, include proper headers to use functs, like printf, scanf
//quick and easy to use
//standarized
//accurate

#include <stdio.h>
#include <math.h>

//int main(void) {
//	//double a = 4;
//	//double sqar_a = 0;
//	////function arguments can be constant variable or expression
//	//sqar_a = sqrt(a); //passes an argument as variables
//	//printf("Value is %.2f", sqar_a);
//	//printf("Value is %.2f\n", sqrt(81)); //passes the constant of 81
//	//printf("Value is %.2f", sqrt(9 * 9)); //passes and expression
//	//printf("Value is %.2f", sqrt(a * a)); //also passes and expression
//
//	//given any number, print out each digit for the number
//	int number = 0;
//	int length = 0;
//	int digit = 0;
//	int remainder = 0;
//
//	printf("%s", "Enter the number: ");
//	scanf_s("%d", &number);
//
//	//calculate the length of the number
//	//log10(100) = 2, length of 100 - 999 is log10(number)
//	//log10(1000) = 3
//	length = floor(log10(number)) + 1;
//	//length = ceil(log10(number)); //causes logic bug, will not work for numbers like 100/1000
//	printf("Length of the number is %d", length);
//
//	//89, 89/10 = 8, 89 % 10 = 9
//	//678, 678/100 = 6, 678 % 100 = 78, 78/10 = 7, 78 % 10 = 8
//	//print out each digit number using a for loop
//
//	for (int i = 0; i < length; i++) {
//		digit = floor(number / pow(10, length - i - 1));
//		number = number % (int)pow(10, length - i - 1);
//		printf("%d", digit); //THIS IS NOT PRINTING CORRECT, CHECK TEACHER NOTES
//	}

//user defined function
//your funct should only perform a simple task
//reuse the code
//make the code more readable
//more portable

//return-value-type function-name(parameter-list){  //the header of the function
//body of the function, perform certain task
//}

//int square(int number); //function prototype
//
//int main(void) {
//	int a = 3;
//	int b = 0;
//	b = square(a); //a is the argument
//
//	printf("Square of %d is %d\n", a, b);
//	printf("a is %d\n", a);
//}
////define of the function
//int square(int number){ //function header, number the parameter
//	number = number * number;
//	printf("Inside of function number is %d\n", number);
//	return number;

//function called stack, LIFO data structure
//support function call/return mechanism, also creating/maintaining local variables
//each time a function is called, an entry is pushed onto the stack,
//the entry is stack fram which contains (MISSING NOTES******)
//and when it is returned, the stack frame for that function is pop'd, the control is give back to the caller
//stack frame reverse memory for local variables, when function returns, the stack released the memory MISSING NOTES******
//}