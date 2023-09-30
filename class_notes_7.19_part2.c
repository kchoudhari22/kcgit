//create a to do list, for each entry, it contains task, priority, due date
//store the to do list in todo_list.txt

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct list {
//	char task[200];
//	int priority;
//	char date[20];
//};
//
////store info for one task
//typedef struct list List;
//
//void readList(List* list, int* size, int* count);
//
//int main(void) {
//	int arraySize = 2; //tracking size of dynamic array
//	int count = 0; //checking how many tasks in the to do list
//	List* listA = (List*)malloc(arraySize * sizeof(List));
//	//read everything from the file and store the listA
//	readList(&listA, &arraySize, count);
//
//	//read the todo_list.txt to get all the existing tasks
//	//store the tasks in a structure
//
//	//get action from user input;
//	//call different fncts based on user input
//	//if user input is -1, end the program
//}
//
//void readList(List* list, int* size, int* count) {
//	//open the to do_list.txt
//	FILE* fPtr;
//	errno_t err;
//	err = fopen_s(&fPtr, "todo_list.txt", "r");
//
//	//string to store the lines
//	char line[100];
//
//	//while loop checks if we are at the end of the line
//	//use while loop to read each line in the txt
//	while (fgets(line, sizeof(line), fPtr != NULL) {
//		fscanf_s(line, "%s%d%s", sizeof(task), priority, sizeof(date));
//
//	}
//	//check the space,
//	//if out of space, expand the array
//	//store the infor to the array
//
//	fclose(fPtr);
//}