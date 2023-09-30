#include <stdio.h>
#include <stdlib.h>

//write a function expandArray which changes the array size
//and takes two parameters, the first one is the array
//the second one is the new size of the array
//write a function printArray which prints each element of the array
//which takes two parameters, the first one is the array
//the second is the size of the array
//decide if the function needs to return anything

//void printArray(int* array, int size);
//int* expandArray(int* array,int size);
//
//int main(void) {
//	int* array = (int*)malloc(4 * sizeof(int));
//	for (int i = 0; i < 4; i++) {
//		array[i] = i;
//	}
//	
//	array = expandArray(array, 100);
//	printf("Address of array after expandArray is %p\n", array);
//	printArray(array, 100);
//	
//}
//
//void printArray(int* array, int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%4d", array[i]);
//	}
//}
//
//int* expandArray(int* array, int size) {
//	int* newPtr = (int*)realloc(array, (size) * sizeof(int));
//	if (newPtr != NULL) {
//		for (int i = 0; i < size; i++) {
//			newPtr[i] = i;
//		}
//		array = newPtr;
//		printf("Address of newPtr is %p\n", newPtr);
//		printf("Address of array in expandArray is %p\n", array);
//		return newPtr;
//	}
//	else {
//		puts("Allocation failed");
//		return array;
//	}
//}

//same program but... GETTING SIZE FROM USER

//void printArray(int* array, int size);
//int* expandArray(int* array, int* size);
//
//int main(void) {
//	int size = 4;
//	int* array = (int*)malloc(4 * sizeof(int));
//	
//	for (int i = 0; i < 4; i++) {
//		array[i] = i;
//	}
//
//	printArray(array, size);
//	printf("Address of array is %p\n", array);
//	puts("-----");
//
//	array = expandArray(array, &size);
//	printf("Address of array after expandArray is %p\n", array);
//	printf("New size is %p\n", size);
//	printArray(array, size);
//
//}
//
//void printArray(const int* const array, int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%4d", array[i]);
//	}
//	puts("");
//}
//
//int* expandArray(int* const array, int* const size) {
//	printf("Please enter the new size: ");
//	scanf_s("%d", size);
//	int* newPtr = (int*)realloc(array, (*size) * sizeof(int));
//	if (newPtr != NULL) {
//		for (int i = 0; i < size; i++) {
//			newPtr[i] = i;
//		}
//		//array = newPtr;
//		printf("Address of newPtr is %p\n", newPtr);
//		printf("Address of array in expandArray is %p\n", array);
//		return newPtr;
//	}
//	else {
//		puts("Allocation failed");
//		return array;
//	}
//}


//#include<ctype.h>

//checking if the character is a sigit, if it is a digit return a true value, if not return 0

//string conversion functions

//standard I/O library
//getchar(): return the next character from the stdin
//fgets

//int main(void) {
//	////checking if the character is a sigit, if it is a digit return a true value, if not return 0
//	//printf("%d\n", isdigit('8'));
//	//printf("%d\n", isdigit('a'));
//	//printf("%s\n", isdigit('8') ? "8 is a digit" : "8 is not a digit"); 
//
//	////string conversion functions
//	//char* string = "52 is recieved";
//	//char* stringPtr = NULL;
//	////function returns 0 if it cannot convert part of the string to a double
//	////stringPtr points to the first character after converting the string
//	//double d = strtod(string, &stringPtr);
//	//printf("%.2f %s\n", d, stringPtr);
//	////strotl converts string to long
//	////strtoul converts tring to unsigned long
//
//	//standard I/O library
//	//getchar(): return the next character from the stdin
//	//fgets
//	char str[10] = "";
//	int size;
//	printf("How many loops do you want to run? ");
//	scanf_s("%d", &size);
//	while (getchar() != '\n'); //consume any characters left in the string
//
//	//same as the while statement above
//	/*while (1)
//	{
//		if (getchar() == '\n') {
//			break;
//		}
//	};*/
//	
//	//same as the 2 while statements above
//	/*char c;
//	do {
//		c = getchar();
//		printf("--read back %c--\n", c);
//
//	} while (c != '\n');*/
//
//	for (int i = 0; i < size; i++) {
//		printf("Enter string: ");
//		//reads characters from the specified stream into the array str
//		//until a newline or EOF character is encountered
//		//or n-1 bytes are read
//		fgets(str, 10, stdin);
//		printf("Str is %s\n", str);
//	}
//
//}