/*
COP3223 Summer 2023 Assignment 2.3
Copyright 2023 Choudhari Katelyn
*/

//A program that assigns seats on a flight with a max of 6 seats

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

//#define SIZE 6 //total nmbr of plane seats
//
//int seats[SIZE] = { 0 }; //init array
//int searchSeat(int section);//fnct prototype
//void printBoardingPass(int seatNumber, int section);
//
//int main() {
//    srand(time(NULL)); //init random number generator
//    //init variables
//    int section, seatNumber;
//    int choice;
//
//    do {
//        printf("Please type 1 for \"first class\" \n");//get user input
//        printf("Please type 2 for \"economy\": \n");
//        scanf_s("%d", &section);//read user choice
//
//        seatNumber = searchSeat(section);//call fnct searchSeat
//
//        //check for seat nmbr from searchSeat fnct and prints boarding pass
//        //if there is available seats
//        if (seatNumber != -1) {
//            printBoardingPass(seatNumber, section);//call fnct printBoardingPass
//        }
//        else {
//            printf("No seats available in this class.\n");
//            printf("Would you like to be put in a different class? YES 1 NO 0 : ");//asks user if they want a different class
//            scanf_s("%d", &choice);
//
//            if (choice == 1) {
//                section = (section == 1) ? 2 : 1; //change choice
//                seatNumber = searchSeat(section);
//                if (seatNumber != -1) {
//                    printBoardingPass(seatNumber, section);//call fnct printBoardingPass
//                }
//                else {
//                    printf("Next flight leaves in 3 hours.\n");
//                }
//            }
//            else {
//                printf("Next flight leaves in 3 hours.\n");
//            }
//        }
//
//        printf("Anymore passengers? YES 1 NO 0: ");
//        scanf_s("%d", &choice);
//
//    } while (choice == 1);//iterate while there are still more passengers
//
//    return 0;
//}
//
////fnct prints seat number and flight class / boarding pass
//void printBoardingPass(int seatNumber, int section) {
//    printf("Seat Number: %d\n", seatNumber);
//    printf("Section: %s\n", (section == 1) ? "First Class" : "Economy");
//}
//
////fnct searches for available seats in user chosen section
//int searchSeat(int section) {
//    int a;
//    int b;
//    if (section == 1) {//if first class 
//        a = 0;
//        b = SIZE / 2 - 1;//half of array for first class seats
//        //and takes away a seat once a seat is booked
//    }
//    else {//if economy class
//        a = SIZE / 2;//half of array for economy class seats
//        b = SIZE - 1;//and takes away a seat once a seat is booked
//    }
//
//    //checks for available seats in that section
//    for (int i = a; i <= b; i++) {
//        if (seats[i] == 0) {
//            seats[i] = 1; //seat taken
//            return i + 1; //return seat number
//        }
//    }
//    return -1; //returns when no seats in that section available
//}