/*
COP3223 Summer 2023 Assignment 3.2
Copyright 2023 Choudhari Katelyn
*/

//Students records program.
//Searches student information by either
//student first or last name, or id number.

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define SIZE 6
//
//struct student { //create struct
//    char firstName[20];
//    char lastName[20];
//    int identificationNumber;
//    char grade;
//};
//
//typedef struct student Student; 
//
////fnct prototypes
//void search_firstName(char *first, Student *Students);
//void search_lastName(char *last, Student *Students);
//int search_id(int id, Student *Students);
//void printUsingIndex(Student stud);
//
//int main(void) {
//    int searchType;
//
//    Student Students[6] = { 0 }; //arrary of struct
//
//    //student information
//    strcpy_s(Students[0].firstName, 20, "John");
//    strcpy_s(Students[0].lastName, 20, "Johnson");
//    Students[0].identificationNumber = 895645;
//    Students[0].grade = 'A';
//
//    strcpy_s(Students[1].firstName, 20, "Jake");
//    strcpy_s(Students[1].lastName, 20, "Michaelson");
//    Students[1].identificationNumber = 236598;
//    Students[1].grade = 'A';
//
//    strcpy_s(Students[2].firstName, 20, "Sally");
//    strcpy_s(Students[2].lastName, 20, "Weber");
//    Students[2].identificationNumber = 225584;
//    Students[2].grade = 'C';
//
//    strcpy_s(Students[3].firstName, 20, "Tou");
//    strcpy_s(Students[3].lastName, 20, "Xiong");
//    Students[3].identificationNumber = 364875;
//    Students[3].grade = 'B';
//
//    strcpy_s(Students[4].firstName, 20, "Jacquelyn");
//    strcpy_s(Students[4].lastName, 20, "Jackson");
//    Students[4].identificationNumber = 984587;
//    Students[4].grade = 'D';
//
//    strcpy_s(Students[5].firstName, 20, "John");
//    strcpy_s(Students[5].lastName, 20, "White");
//    Students[5].identificationNumber = 560258;
//    Students[5].grade = 'C';
//    
//    Student temp;
//
//    //while loops determines the search parameter (name or id #) and then calls the
//    //appropriate fnct to output all of the students info
//    while (1) {
//        printf("Enter the search type: 0 for first name, 1 for last name, 2 for ID number: ");
//        scanf_s("%d", &searchType);
//
//        if (searchType == 0) {
//            printf("Enter the first name you want to search: ");
//            scanf_s("%s", temp.firstName, 20);
//            search_firstName(temp.firstName, Students);
//        }
//        if (searchType == 1) {
//            printf("Enter the last name you want to search: ");
//            scanf_s("%s", temp.lastName, 20);
//            search_lastName(temp.lastName, Students);
//        }
//        if (searchType == 2) {
//            printf("Enter the ID number you want to search: ");
//            scanf_s("%d", &temp.identificationNumber);
//            search_id(temp.identificationNumber, Students);
//        }
//    }
//}
//
//void search_firstName(char* first, Student* Students) {
//    for (int i = 0; i < SIZE; i++) {
//        if (strcmp(Students[i].firstName, first) == 0) {
//            printUsingIndex(Students[i]);
//        }
//    }
//}
//
//void search_lastName(char* last, Student* Students) {
//    for (int i = 0; i < SIZE; i++) {
//        if (strcmp(Students[i].lastName, last) == 0) {
//            printUsingIndex(Students[i]);
//        }
//    }
//}
//
//int search_id(int id, Student* Students) {
//    for (int i = 0; i < SIZE; i++) {
//        if (Students[i].identificationNumber == id) {
//            printUsingIndex(Students[i]);
//            return 1;
//        }
//    }
//    return 0;
//}
//
////print fnct
//void printUsingIndex(Student stud) {
//    printf("%4s, %4s, %4d, %2c \n", stud.firstName, stud.lastName,
//        stud.identificationNumber, stud.grade);
//}