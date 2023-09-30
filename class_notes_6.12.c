//#include <stdio.h>

//int plus_one();

//static storage duration: exist at the beginning of the program
//until its termianted. It only has one copy in the program
//static keywords: used for variables
//extern: used for global variables and functions

//scope: where you can access the variable/indentifier
//function scope:
//file scope:
//block scope: 
//function-prototype scope:identifier used in the parameter
//list of the function prototype

//int main(void) {
//	printf("%d\n", plus_one());
//	printf("%d\n", plus_one());
//}
//
//int plus_one() {
//	static int number = 0; //local variable with automatic storage duration
//	number++;
//	return number;
//}

//void useLocal(void);
//void useStaticLocal(void);
//void useGlobal(void);
//
//int x = 1; //global variable
//
//int main(void) {
//	int x = 5; //local variable to main
//	printf("Local x in outer scope of main is %d\n", x);
//
//	{
//		int x = 7; //local variable to new scope
//		printf("Local x in inner scope of amin is %d\n", x);
//	}
//
//	printf("Local x in outer scope of main is %d\n", x);
//
//	useLocal();
//	useStaticLocal();
//	useGlobal();
//	useLocal();
//	useStaticLocal();
//	useGlobal();
//
//	printf("\n Local x in main is %d\n", x);
//}
//
//void useLocal(void) {
//	int x = 25;
//	printf("\n Local x in useLocal is %d after entering function\n", x);
//	x++;
//	printf("\n Local x in useLocal is %d before exiting function\n", x);
//}
//
//void useStaticLocal(void) {
//	static int x = 50;
//	printf("\n Local x in useStaticLocal is %d after entering function\n", x);
//	x++;
//	printf("\n Local x in useStaticLocal is %d before exiting function\n", x);
//}
//
//void useGlobal(void) {
//	printf("\n Local x in useGlobal is %d before exiting function\n", x);
//	x++;
//	printf("\n Local x in useGlobal is %d before exiting function\n", x);
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//generate a random number
//int main(void) {
//	int seed = 20;
//	srand(time(NULL));
//	int value = rand(); //rand function generate and int between 0 and RAND_MAX
//	printf("Value is %d", value);
//}

//program to roll a dice (1-6), roll it for 8000
//calculate number for each
//print out
//side count
//1     100
//2     200

//int main(void) {
//	int s1 = 0;
//	int s2 = 0;
//	int s3 = 0;
//	int s4 = 0;
//	int s5 = 0;
//	int s6 = 0;
//
//	srand(time(NULL));
//
//	for (int i = 0; i < 8000; i++) {
//		int result = 1 + rand() % 6;
//
//		switch (result) {
//		case 1:
//			s1++;
//			break;
//		case 2:
//			s2++;
//			break;
//		case 3:
//			s3++;
//			break;
//		case 4:
//			s4++;
//			break;
//		case 5:
//			s5++;
//			break;
//		case 6:
//			s6++;
//			break;
//		}
//	}
//	printf("%s %8s\n", "size", "count");
//	printf("1%11d\n", s1);
//	printf("2%11d\n", s2);
//	printf("3%11d\n", s3);
//	printf("4%11d\n", s4);
//	printf("5%11d\n", s5);
//	printf("6%11d\n", s6);
//}

//recursive function is a function that calls itself
//directly or indirectily through another function

//#include <stdio.h>

//int main(void) {
//	int factorial(int n);
//	int result = factorial(5);
//	printf("Result is %d", result);
//}
//
//int factorial(int n){
//	if (n == 1) { //base case
//		return 1;
//	}
//	else {
//		return n * factorial(n - 1);
//	}
//}

//program to calcualte fibonacci number
//			0, 1, 1, 2, 3, 5, 8, 13, 21...
//index is: 1, 2, 3, 4, 5, 6, 7, 8, 9...

//#include <stdio.h>
//
//int fib(int index);
//
//int main(void) {
//	int n = 3;
//	int fibonacci = 0;
//	fibonacci = fib(n);
//	printf ("Index %d, fibonacci number is %d", n, fibonacci);
//}
//
//int fib(int index) {
//	if (index == 0 || index == 1) { //base case
//		return index;
//	}
//	else {
//		return fib(index - 1) + (index - 2); //recursive function
//	}
//}

//recursion vs. interation
//all involve repetition
//all have termination case
//all gradually approach to the termination