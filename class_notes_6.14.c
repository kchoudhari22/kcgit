//enumerations: user defined data type,
//used to assign names to int constant
//make the code easy to read and maintain

//#include <stdio.h>

//enum flag(constant1, constant2, ...);
//enum week { Mon = 3, Tue, Wed, Thu, Fri, Sat, Sun };
//
//int main(void) {
//	enum week day;
//	day = Fri;
//	printf("%d\n", day);
//	day = Wed;
//	for (int i = Mon; i <= Sun; i++);
//		printf("%d", Wed);
//}

//write a program to randomly generate the day of the week,
//if Mon or Wed, print Don't forget to have class
//if Fri, print Lab due today
//if Tue or Thu, Sleep
//if Sat or Sun, print Alligator hunting

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//enum week { Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun};
//
//int main(void) {
//	//generate random number between 1-7
//	srand(time(NULL));
//	int day = 0;
//	day = rand() % 7 + 1;
//	printf("Day is %d\n", day);
//
//	//use switch to perform different actions based on dau=y
//	switch (day) {
//	case Mon:
//	case Wed:
//		puts("Dont forget to go to class");
//		break;
//	case Tue:
//	case Thu:
//		puts("Rest");
//		break;
//	case Fri:
//		puts("Lab due today");
//		break;
//	default:
//		puts("Alligator hunting");
//	}
//}

//array: a group of elements that have the same type
//and store continously in memory

//#include <stdio.h>
//
//#define size 5 //symbolic constant 
//
//int main(void) {
//	int a[4];
//	//assign the value 1-4 for each element
//	a[0] = 1;
//	a[1] = 2;
//	a[2] = 3;
//	a[3] = 4;
//	//init the array by for loop
//	//or you can write it like this
//	for (size_t i = 0; i < 4; i++) { //size_t recommended to use when using an array but you can use int
//		a[i] = i + 1;
//	}
//	//or you can write it like this
//	for (size_t i = 0; i < 4; i++) {
//		printf("Index = %zu, value = %d\n", i, a[i]);
//	}
//	
//	puts("----------");
//	
//	//init with initializer list
//	//if there are fewer initializers than the array items, the remaining items init to 0
//	int b[5] = {1,2,3}; //in curly brackets is a list //[]for index position in array
//	//int b[5] = {0}; //a way to assign all element values to zero
//	for (size_t i = 0; i < 5; i++) {
//		printf("Index = %zu, value = %d\n", i, b[i]);
//	}
//	
//	puts("----------");
//	
//	int c[] = { 1,2,3 }; //when you leave the [] empty it will take how many are in the string, in this case 3
//	for (size_t i = 0; i < 3; i++) {
//		printf("Index = %zu, value = %d\n", i, c[i]);
//	}
//	
//	puts("----------");
//	//int d[2] = {1,2,3}; //compiler error if there are more initializers than the size of the array
//
//	int d[size] = { 1, 2, 3, 4, 5 }; //[size] will be replaced with the value in the header #define size value
//	//symbolic constant is not a variable, cannot do assignment to it
//	//for example you cannot do size = 6; on the next line because its not a variable
//}