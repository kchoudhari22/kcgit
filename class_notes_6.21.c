//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

//array notes, sorting arrays, character arrays

//#define SIZE 5
//enum status{not_find, find};
//
//int main(void) {
//	/*int list[5] = {1,1,1,1,1};//init all elements to 1
//	int list[5] = { 0 };//init all elements to 0
//	list[3] = 5;//changes the 4th element value to 5
//	printf("%d", list[3]);*/
//
//	//randomly generate a number between 1 to 10
//	//check if the number exist in the list
//	//if it exists, print out the number and index
//	//if does not exist, print out number number doesn't exist
//
//	srand(time(NULL));
//	int list[SIZE] = { 2, 6, 8, 4, 9 };
//	enum status status_t = not_find; //0 means ot find number in the array yet, 1 means find
//	
//	//get random number
//	int num = rand() % 10 + 1;//get range between 10, creates range 1 - 9 plus 1 = 10
//	printf("The number is %d\n", num);
//
//	//checking if the numebr is in the array
//	for (int i = 0; i < SIZE; i++) {
//		if (num == list[i]) {
//			printf("Find the number %d at index %d\n", num, i);
//			status_t = find;
//			break;
//		}
//		//else if (i == 4 && num != list[i]){ //if random numbers are les than 5 numbers and not in the list
//		//	printf("Cannot find number %d in the array\n", num);
//
//		//}
//	}
//
//	if (status_t == not_find) {//if it cannot find in the array
//		printf("Cannot find number %d in the array\n", num);
//	}
//}

////write a program to sort the array, smallest to largest value
////bubble sort
//#define SIZE 10
//
//int main(void) {
//	int a[SIZE] = { 3,4,8,2,5,0,4,6,1,7 };
//	puts("Data in original order");
//	for (int i = 0; i < SIZE; i++) {
//		printf("%4d", a[i]);
//	}
//
//	//bubble sort, n*2, sorts largest to the bottom
//	for (int pass = 0; pass < SIZE; pass++) {
//		for (int i = 0; i < SIZE - 1; i++) {
//			if (a[i] > a[i + 1]) {
//				int temp = a[i];
//				a[i] = a[i + 1];
//				a[i + 1] = temp;
//			}
//		}
//	}
//	//another way to sort the numbers by popping smalles to top
//	int smallest = 0;
//	for (int i = 0; i < SIZE; i++) {
//		smallest = a[i];
//		for (int j = i + 1; j < SIZE; j++) {
//			if (smallest > a[j]) {
//				int temp = a[j];
//				a[j] = a[i];
//				a[i] = temp;
//				smallest = a[j];
//			}
//		}
//	}
//
//	puts("\nData in sorted order");
//	for (int i = 0; i < SIZE; i++) {
//		printf("%4d", a[i]);
//	}
//}

////character array which stores a string
//int main(void) {
//	char string1[5];//this array can have 4 individual characters plus a string terminating null character \0
//	char string2[5] = { 'a','b','c','d','\0' };//init the character array
//	char string3[] = "abcd";//same as the line above, the size of the string will be 5 as well
//	
//	printf("%c  %d\n", string2[2], string2[2]);
//	printf("%c  %d\n", string2[4]), string2[4]);
//	scanf_s("%4s", string1, 5);//scanf_s requires the argument for the strong and the arrays number of elements to prevent buffer overload
//	//when using scanf_s in array you do not need the &
//	
//	printf("%s", string1);
//	string1[2] = 't';
//	printf("%s", string1);
//}

//aray size is 6, define the array, init the array with scanf
//then print out each characters in the array except the termination character
//abc

//#define SIZE 6
//int main(void) {
//	char string[SIZE] = "";
//	printf("%s", "Enter a string: ");
//	scanf_s("%5s", string, SIZE);
//
//	//print out each character in the array
//	for (int i = 0; i < SIZE && string[i] != '\0'; i++) {
//		if (string[i] == '\0') {
//			break;
//		}
//		printf("%c ", string[i]);
//	}
//}

////array is passed to function by reference, which means it passes the address of that array
//#define SIZE 5
//
//void modifyArray(int array[], int SIZE);
//
//int main(void){
//	char array[4] = "abc";
//    printf("array = %p\n", &array);//&p to print address with hex value
//	printf("array = %p\n", array);
//	printf("array[0] = %p\n", &array[0]);
//
//	int a[SIZE] = { 0,1,2,3,4 };
//	puts("Original array");
//	for (int i = 0; i < SIZE; i++) {
//		printf("%3d", a[i]);
//	}
//	modifyArray(a, SIZE);
//	puts("Updated array");
//	for (int i = 0; i < SIZE; i++) {
//		printf("%3d", a[i]);
//	}
//}
//
//void modifyArray(int array[], int SIZE) {
//	for (int i = 0; i < SIZE; i++) {
//		array[i] += 2;
//	}
//
//}