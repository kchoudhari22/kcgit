//FILES OPEN/CLOSE
//write to a file:
//define a pointer pointing to a file structure
//fopen fnct to open the file, with mode w
//call fprintf/fputs fnct to write to the file
//call fclose fnct to close the file

//#include <stdio.h>
//#include <string.h>
//int main(void) {
//	FILE* fPtr;
//	errno_t err;
//
//	//write a file
//	//fopen_s returns a value to indicate if the file is open or not
//	err = fopen_s(&fPtr, "example1.3.txt", "w"); //example1.3.text would be the text file on your PC
//	if (err == 0) {
//		fprintf(fPtr,"%s","This is a test");
//	}
//
//
//	err = fopen_s(&fPtr, "example1.3.txt", "a");
//	if (err == 0) {
//		fprintf(fPtr, "%s", "This is a test");
//		fprintf(fPtr, "%s", "This is another test");
//		fputs("This is a test\n", fPtr);
//		fputs("Final test\n", fPtr);
//	}
//
//	err = fopen_s(&fPtr, "example1.3.txt", "a");
//	if (err == 0) {
//		char line[100];
//		fprintf(fPtr, "%s", "This is a test");
//		fprintf(fPtr, "%s", "This is another test");
//		fputs("This is a test\n", fPtr);
//		fputs("Final test\n", fPtr);
//		//rewind makes the pointer point to the beginning of the file
//		rewind(fPtr);
//		fgets(line, sizeof(line), fPtr);
//		printf("%s", line);
//	}
//
//
//	//read a file
//	err = fopen_s(&fPtr, "example1.3.txt", "r");
//	if (err == 0) {
//		char line[100];
//		//read multiple lines
//		fgets(line, sizeof(line), fPtr);
//		printf("%s\n", line);
//		fgets(line, sizeof(line), fPtr);
//		printf("%s\n", line);
//		fgets(line, sizeof(line), fPtr);
//		printf("%s\n", line);
//		fgets(line, sizeof(line), fPtr);
//		printf("%s\n", line);
//	}
//
//	err = fopen_s(&fPtr, "example1.3.txt", "r");
//	if (err == 0) {
//		char line[100];
//		//read line 1 at a time using fgets
//		fgets(line, sizeof(line), fPtr);
//		printf("%s\n", line);
//		//stop reading when it hits newline, space, tab
//		fscanf_s(fPtr, "%s", line, sizeof(line));
//		printf("%s\n", line);
//	}
//
//	err = fopen_s(&fPtr, "example1.3.txt", "r");
//	if (err == 0) {
//		char line0[100];
//		char line1[100];
//		char line2[100];
//		char line3[100];
//		//read 1 line, store each line in a variable
//		fgets(line0, sizeof(line0), fPtr);
//		printf("%s\n", line0);
//		fgets(line1, sizeof(line1), fPtr);
//		printf("%s\n", line1);
//		fgets(line2, sizeof(line2), fPtr);
//		printf("%s\n", line2);
//		fgets(line3, sizeof(line3), fPtr);
//		printf("%s\n", line3);
//
//	fclose(fPtr);
//	(*line2) = "New line\n";
//
//	strcpy(line2, sizeof(line2), "Change to a new line again\n");
//	printf("%s", line2);
//
//	err = fopen_s(&fPtr, "example1.3.txt", "w");
//	if (err == 0) {
//		fputs(line0, fPtr);
//		fputs(line1, fPtr);
//		fputs(line2, fPtr);
//		fputs(line3, fPtr);
//	}
//}

//print below student information into student.txt

//Mike	20	89.0
//Chris	25	98.3
//Zoe	19	87.2
//when read back the file finds out the age and grade for Chris

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main(void) {
//	//write to the file
//	FILE* fPtr;
//	errno_t err;
//	err = fopen_s(&fPtr, "student.text", "w");
//	//store all student info in a newline
//	fputs("Mike		20	89.0\n", fPtr);
//	fputs("Chris	25	98.3\n", fPtr);
//	fputs("Zoe		19	87.2\n", fPtr);
//	fclose(fPtr);
//
//	err = fopen_s(&fPtr, "student.text", "r");
//	char line[200];
//	fgets(line, sizeof(line), fPtr);
//
//	//will read all 3 lines
//	err = fopen_s(&fPtr, "student.text", "r");
//	char line[200];
//	while (fgets(line, sizeof(line), fPtr) != NULL) {
//		printf("%s", line);
//	}
//	
//	fclose(fPtr);
//
//	err = fopen_s(&fPtr, "student.text", "r");
//	char line[200];
//	char name[20];
//	int age;
//	float grade;
//	while (fgets(line, sizeof(line), fPtr) != NULL) {
//		fscanf_s(line, "%s"	"%d"	"%f", name, sizeof(name), &age, grade);
//		printf("%20s%5d%10f", name, age, grade);
//	}
//
//	fclose(fPtr);
//
//	err = fopen_s(&fPtr, "student.text", "r");
//	char line[200];
//	char name[20];
//	int age;
//	float grade;
//	while (fgets(line, sizeof(line), fPtr) != NULL) {
//		fscanf_s(line, "%s%d%f", name, sizeof(name), &age, &grade);
//		
//		if (strcmp(name, "Chris") == 1) {
//			printf("Age = %d, grade is %.2f", age, grade);
//		}
//	}
//
//	fclose(fPtr);
//}