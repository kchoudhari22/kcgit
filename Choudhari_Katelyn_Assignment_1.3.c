/*
COP3223 Summer 2023 Assignment 1.3
Copyright 2023 Choudhari Katelyn
*/

//A program that prints a diamond shape by reading an odd number
//in the range 1 to 19 to specify the number of rows in the
//diamond and displays a diamond of the appropriate size.

#include <stdio.h>
/*
int main(void){

    //init variables
    int row = 0;
    int i = 0;
    int j = 0;
    int blank;

    //get and read number of rows from user
    printf("%s", "Please enter number of rows (odd number from 1 - 19): ");
    scanf_s("%d", &row);

    //check for odd or even number
    if (row % 2 == 0) { //break if even number
        printf("%s", "Please enter number of rows (odd number from 1 - 19): ");
        scanf_s("%d", &row);
        if (row % 2 == 0)
            return 0;
    }

    else (row % 2 != 0); { //continue if odd number
        //top of diamond
        blank = row / 2;
        for (i = 1; i <= row; i += 2) { //iterates / increments rows
            for (j = 0; j < blank; j++) //iterates spaces
                printf("%s", " ");
            for (j = 0; j < i; j++) //determines number of * for row
                printf("%s", "*");
            puts(" ");//newline
            blank--; //decrements spaces
        }

        //bottom of diamond
        blank = 1;
        for (i = row - 2; i >= 1; i -= 2) { //iterates / decrements rows
            for (j = 0; j < blank; j++) //iterates spaces
                printf("%s", " ");
            for (j = 0; j < i; j++) //determines number of * for row
                printf("%s", "*");
            puts(" ");//newline
            blank++; //increments spaces
        }
    }
}
*/