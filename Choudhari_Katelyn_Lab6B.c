/*
COP3223 Summer 2023 Lab6B
Copyright 2023 Choudhari Katelyn
*/

//#include <stdio.h>
//
//#define SIZE 50
//
//int Floor[SIZE][SIZE] = { 0 }; // Initialize the floor array to zeros
//int TurtleX = SIZE / 2;      // Starting X position of the turtle
//int TurtleY = SIZE / 2;      // Starting X position of the turtle
//int Direction = 0; // Either 0: right, 1: down, 2: left, 3: up. Default is 0
//
//void printFloor() {
//    // implement the required logic here
//    for (int i = 0; i < SIZE; i++) {
//        for (int j = 0; j < SIZE; j++) {
//            if (Floor[i][j] == 1)
//                printf("*");
//            else
//                printf(" ");
//        }
//        printf("\n");
//    }
//}
//
//void moveForward(int steps, int penDown) {
//    if (Direction == 0) {
//        for (int i = 0; i < steps; i++) {
//            TurtleX++;
//            if (penDown) {
//                Floor[TurtleY][TurtleX] = 1;
//            }
//        }
//    }
//
//    else if (Direction == 1) {
//        for (int i = 0; i < steps; i++) {
//            TurtleY--;
//            if (penDown) {
//                Floor[TurtleY][TurtleX] = 1;
//            }
//        }
//    }
//
//    else if (Direction == 2) {
//        for (int i = 0; i < steps; i++) {
//            TurtleX--;
//            if (penDown) {
//                Floor[TurtleY][TurtleX] = 1;
//            }
//        }
//    }
//
//    else if (Direction == 3) {
//        for (int i = 0; i < steps; i++) {
//            TurtleY++;
//            if (penDown) {
//                Floor[TurtleY][TurtleX] = 1;
//            }
//        }
//    }
// }
//
//int main() {
//    int penDown = 0; // Flag (variable) to indicate if the pen is down or up
//
//    // For the sequence of commands below we should get a 12-by-12 square on the
//    // floor. You can also read one command at a time using a scanf statement
//    // inside the while loop
//    int commands[] = { 2, 5, 12, 3, 5, 12, 3, 5, 12, 3, 5, 12, 1, 6, 9 };
//    // int commandCount = sizeof(commands) / sizeof(commands[0]);
//    int commandIndex = 0;
//
//    printf("\n *** Initiating turtle graphics: *** \n");
//    while (1) {
//        int command = commands[commandIndex];
//
//        if (command == 1) { // Pen up
//            penDown = 0;
//        }
//        else if (command == 2) { // Pen down
//            penDown = 1;
//        }
//        else if (command == 3) { // Turn right
//            // implement the required logic here
//            Direction = (Direction + 1) % 4;
//        }
//        else if (command == 4) { // Turn left
//            // implement the required logic here
//            Direction = (Direction + 3) % 4;
//        }
//        else if (command == 5) { // Move forward
//            commandIndex++;
//            int steps = commands[commandIndex];
//            moveForward(steps, penDown);
//        }
//        else if (command == 6) { // Print the floor
//            printFloor();
//        }
//        else if (command == 9) { // End of data
//            break;
//        }
//
//        commandIndex++;
//    }
//
//    return 0;
//}