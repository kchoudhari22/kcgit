//arrays and pointers
//functions and pointers
//malloc and calloc

#include <stdio.h>
////pass variables by reference using a function
//void swap(int* x, int* y);
//
//int main(void) {
//	int a = 5;
//	int b = 7;
//	swap(&a, &b);
//	printf("a = %d  b = %d", a, b);
//}
//
//void swap(int* x, int* y) {
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}


//bubble sort using functions and passing by reference with pointers
//#define SIZE 5
//
//void bubbleSort(int* array, int size);
//
//int main(void) {
//	int a[SIZE] = (3, 6, 8, 2, 5);
//	puts("Data in original order: ");
//	for (int i = 0; i < SIZE; i++) {
//		printf("%4d", a[i]);
//	}
//
//	bubbleSort(a,SIZE); 
//	puts("\nData in sorted order : ");
//	for (int i = 0; i < SIZE; i++) {
//		printf("%4d", a[i]);
//	}
//}
//
//void bubbleSort(int * array, int size) {
//	for (int pass = 0; pass < size; pass++) {
//		for (int i = 0; i < size - 1; i++) {
//			if (array[i] > array[i + 1]) {
//				//switch the value
//				swap();
//				/*int temp = array[i];
//				array[i] = array[i + 1];
//				array[i + 1] = temp;*/
//			}
//		}
//
//	}
//}
//
//void swap() {
//	//perform same as lines 26-28 do above
//}


//int main(void) {
//	//happy friday rest
//	//char c[3][10] = { "Happy", "Friday", "Rest" };
//	//printf("%s\n", c[1]);//prints second string friday
//	//printf("Size of c is %zu\n", sizeof(c));
//
//	//arrays of pointers to store strings
//	char* cPtr[3] = { "Happy", "Friday", "Rest" };
//	printf("%s\n", cPtr[1]);//prints second string friday
//	printf("Size of cPtr is %zu\n", sizeof(cPtr));//size of pointer * 3 because there are 3 elements
//	printf("Size of cPtr is %zu\n", sizeof(cPtr[2]));//a pointer is 8 bytes
//
//	//print out each string
//	for (int i = 0; i < 3; i++) {
//		printf("\nString is %s\n", cPtr[i]);//use pointer and array index to print a string
//		//print out each character in each string
//		for (int j = 0; cPtr[i][j] != '\0'; j++) {
//			printf("%c ", cPtr[i][j]);
//		}
//		puts("");
//	}
//	puts("");
//	for (int i = 0; i < 3; i++) {
//		printf("\nString is %s\n", *cPtr + i);//use pointer and pointer notation/offset to print a string
//		//print out each character in each string
//		for (int j = 0; (*(cPtr +i))[j]!= '\0'; j++) {//use pointer and offset to get string then use index
//			//can also do: for (int j = 0; *(*(cPtr +i)+j) != '\0'; j++)
//			//                 printf("%c ", *(*(cPtr + i)+j));
//			printf("%c ", (*(cPtr + i))[j]);
//		}
//		puts("");
//	}
//}

//function name is the string address in memory of that
// block of code which perform the functions tasks
//a pointer to a function contains the address of the
//function in memory
//we can pass a pointer of function to another function
//it is usually used in a menu driven system
//int add(int num1, int num2);
//int sub(int num1, int num2);
//int math(int num1, int num2, int(*action)(int a, int b));
//
//int main(void) {
//	int a = 8;
//	int b = 5;
//	int action = 0;
//	int result = 0; 
//
//	printf("Please input the value, 1 = add, 2 = sub: ");
//	scanf_s("%d", &action);
//	if (action == 1) {
//		result = math(a, b, add);
//	}
//	if (action == 2) {
//		result = math(a, b, sub);
//	}
//	printf("Result = %d", result);
//}
//
////int(*action)(int a, int b) is a parameter that a pointer to a function
////function will recieve two int and return an int
//int math(int num1, int num2, int(*action)(int a, int b)) {
//	int result = 0;
//	//call the function, deference it, calling the function through a pointer explicitly
//	result = ((*action)(num1, num2));//add(num1, num2)
//	return result;
//}
//
//int add(int num1, int num2) {
//	return num1 + num2;
//}
//
//int sub(int num1, int num2) {
//	return num1 = num2;
//}

////malloc and calloc
//#include <stdlib.h>
//int main(void) {
//	int a[5] = { 0 };
//	//dynamic array will init with ;variable size at runtime, the size can be modified
//	//to expand or shrink
//	//use malloc to dynamically allocate a single large block of memory
//	//ptr = (cast_type*)malloc(byte-size);
//
//	int* ptr;
//	int size = 10;
//
//	ptr = (int*)malloc(size * sizeof(int));
//	if (ptr == NULL) {
//		puts("Memory is not located.");
//	}
//	else{
//		for (int j = 0; j < size; j++) {
//			ptr[j] = j;
//		}
//		for (int i = 0; i < size; i++) {
//			printf("%d ", *(ptr + i));
//		}
//	}
//
//	puts("");
//	
//	//calloc: allocates the specified number of blocks and init them to 0
//	//ptr = (cast_type*)calloc(n, elmement-size);
//
//	int* cPtr;
//	size = 5;
//	cPtr = (int*)calloc(size, sizeof(int));
//
//	if (cPtr == NULL) {
//		puts("Memory is not located.");
//	}
//	else {
//		for (int i = 0; i < size; i++) {
//			printf("%d ", *(cPtr + 1));
//		}
//	}
//}