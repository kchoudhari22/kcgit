/*
COP3223 Summer 2023 Assignment 3.1
Copyright 2023 Choudhari Katelyn
*/

//A program that takes in names from the user and stores them in a dynamic array of strings.
//The user will then be asked to enter a name, to which its index will be returned,
//and the user will be asked to remove a name, and the updated list of names will be printed.

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define NAMELENGTH 50
//
////fnct prototypes
//int findName(char** userNamesPtr, int counter, char name[NAMELENGTH]);
//char** removeName(char** userNamesPtr, int *counter, char name[NAMELENGTH]);
//char** expandArray(char** sPtr, int size);
//void printList(char** sPtr, int counter);
//
//
//int main(void) {
//	char** userNamesPtr = (char**)malloc(4 * sizeof(char*));//allocates memory for 4 character pointers given by userNamesPtr
//	if (userNamesPtr == NULL)
//	{
//		exit(1);
//	}
//		
//	int counter = 0;
//	int size = 4;
//
//	while (1) {
//		char* name = malloc(NAMELENGTH * sizeof(char));//allocates memory for one name
//		if (name == NULL)	exit(1);
//
//		printf("%s", "Enter name: ");//get user input of names
//		scanf_s("%s", name, NAMELENGTH);//read user input of names
//
//		if (strcmp(name, "done")== 0) {//if user enters done, stop prompting for names and proceed
//			printList(userNamesPtr, counter);
//			break;
//		}
//
//		if (counter == size) {//keep a counter of number of names entered and
//			size = size * 2;//expand size of array
//			userNamesPtr = expandArray(userNamesPtr, size);//call expandArray fnct
//		}
//		
//		userNamesPtr[counter] = name;//store the name in pointer array
//		counter++;//keep track of number of names in the pointer array
//	}
//
//	char fName[NAMELENGTH];
//	printf("%s", "Enter name you want to find: ");//get user name to search
//	scanf_s("%s", fName, NAMELENGTH);//read user name to search
//	int index = findName(userNamesPtr, size, fName);//call findName fnct and store that name in index
//	if (index == -1) {//if index not found print statement below
//		printf("%s", "Name not found.");
//	}
//	else {//if name and its index is found print the name and index for the user
//		printf("Found %s at index: %d\n", fName, index);
//	}
//
//	printf("%s", "Enter name you want to remove: ");//get user name to remove
//	scanf_s("%s", fName, NAMELENGTH);//read user name to remove
//	userNamesPtr = removeName(userNamesPtr, &counter, fName);//call removeName funct
//	printList(userNamesPtr, counter);//print new list with removed name
//}
//
//char** expandArray(char** userNamesPtr, int size) {//allocate and expand memory for more names entered
//	userNamesPtr = (char**)realloc(userNamesPtr, (size) * sizeof(char*));//doubles the size of the memory in the pointer array
//	if (userNamesPtr == NULL) {
//		exit(1);
//	}
//	return userNamesPtr;//returns the names in the array
//}
//
//int findName(char** userNamesPtr, int counter, char name[NAMELENGTH]) {//searches for the name in the array
//	for (int i = 0; i < counter; i++) {
//		if(strcmp(name, userNamesPtr[i]) == 0)//uses stringcopy to find the string, or name, in the array and returns its index
//			return i;
//	}	
//	return -1;//returns -1 if the name is not found in the array
//}
//
//char** removeName(char** userNamesPtr, int *counter, char name[NAMELENGTH]) {
//	int index = findName(userNamesPtr, *counter, name);//takes the index of the name from the findName fnct
//	if (index == -1){//if index not found print statement below
//		printf("Name not found");
//	}
//	else {//if name its index is found remove name from the array and shift names and their indexes
//		userNamesPtr[index] = 0;
//		for (int i = index; i < *counter - 1; i++) {
//			userNamesPtr[i] = userNamesPtr[i + 1];//store next name value in previous names index
//		}
//		*counter = *counter - 1;//reduce the counter
//		userNamesPtr = expandArray(userNamesPtr, *counter);//call expandArray fnct, but it is reducing memory
//	}
//	return userNamesPtr;//return list with name removed
//}
//
//void printList(char** userNamesPtr, int counter) {//print fnct to print the list of names when called
//	for (int i = 0; i < counter; i++) {
//		printf("%s\n", userNamesPtr[i]);//prints names only in the userNamesPtr pointer array
//	}
//	puts("\n");
//}