//COP3502 - Programming Assignment 2
//Katelyn Choudhari
//ka609383@ucf.edu

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INITSIZE 10 // The initial size of any row (in terms of number of orders)
#define MAXLEN 50 // The maximum length of a thisName for an order
#define MAXROWS 100000 // The maximum number of rows in the theater

//Struct for order
typedef struct order {
int startSeat;
int endSeat;
char* thisName;
} order;

//Struct for row
typedef struct theaterrow {
order** orders;
int maxSize;
int currentSize;
} theaterrow;

//Fnct prototyes
order* makeOrder(int start, int end, char* thisName);
theaterrow* makeEmptyRow();
int conflict(order* order1, order* order2);
int canAddOrder(theaterrow* thisRow, order* thisOrder);
void addOrder(theaterrow* thisRow, order* thisOrder);
char* getOwner(theaterrow** theater, int row, int seatNum);
char* getRowOwner(theaterrow* thisRow, int seatNum);
int contains(order* myorder, int seatNo);
void freeOrder(order* thisOrder);
void freeRow(theaterrow* thisRow);

int main() {
    theaterrow** theater = calloc(MAXROWS + 1, sizeof(theaterrow*)); //allocates an array, where each element in the array is a pointer to a theater row
    char option[MAXLEN]; //array to store users option input
    int row, start, end; //variables to store row number, start/end seat number
    char thisName[MAXLEN]; //array to store customer name
    
    while (1) {
        printf("Enter option BUY, LOOKUP or QUIT: "); //gets user input
        scanf("%s", option); //read user input
        
        //if the option is BUY than ask for row, seat start and end and customer name
        if (strcmp(option, "BUY") == 0) {
            printf("Enter row, start, end, name: ");
            scanf("%d %d %d %s", &row, &start, &end, thisName); //read user input for row, start/end and name
            order* newOrder = makeOrder(start, end, thisName); //creates a new order
            theaterrow* thisRow = theater[row]; //gets the theater row
            //create a new theater row if it doesn't exist already
            if (thisRow == NULL) {
                thisRow = makeEmptyRow();
                theater[row] = thisRow;
            }
            //adds order to the row
            if (canAddOrder(thisRow, newOrder)) {
                addOrder(thisRow, newOrder);
                printf("SUCCESS\n");
            } else {
                printf("FAILURE\n");
            }
        } else if (strcmp(option, "LOOKUP") == 0) {
            printf("Enter row, seat: ");
            scanf("%d %d", &row, &start); //reads user input for row and seat
            theaterrow* thisRow = theater[row]; //gets the theater row
            //checks is the row exists
            if (thisRow != NULL) {
                char* owner = getRowOwner(thisRow, start); //gets the owner of the seat
                if (owner != NULL) {
                    printf("Owner: %s\n", owner);
                } else {
                    printf("No one\n");
                }
            } else {
                printf("No one\n");
            }
        } else if (strcmp(option, "QUIT") == 0) {
            //frees memory associated with theater rows
            for (int i = 0; i < MAXROWS; i++) {
                if (theater[i] != NULL) {
                    freeRow(theater[i]);
                }
            }
            free(theater); //frees memory allocated for theater array
            break; //exits loop/ends program
        } else {
            printf("Invalid option\n");
        }
    }
    
    return 0;
}

// Returns a pointer to a dynamically allocated order storing the given
// start row, end row, and the thisName thisName. Note: strcpy should be
// used to copy the contents into the struct after its thisName field is
// dynamically allocated.
order* makeOrder(int start, int end, char* thisName){
    order* newOrder = (order*) malloc(sizeof(order));
    newOrder->startSeat = start;
    newOrder->endSeat = end;
    newOrder->thisName = strdup(thisName);
    return newOrder;
}

// This function will allocate the memory for one theaterrow, including
// allocating its array of orders to a default maximum size of 10, and
// setting its current size to 0.
theaterrow* makeEmptyRow(){
    theaterrow* newRow = (theaterrow*) malloc(sizeof(theaterrow));
    newRow->orders = (order**) malloc(INITSIZE * sizeof(order*));
    newRow->maxSize = INITSIZE;
    newRow->currentSize = 0;
    return newRow;
}

// Assuming that order1 and order2 point to orders on the same row, this
// function returns 1 if the orders conflict, meaning that they share
// at least 1 seat in common, and returns 0 otherwise.
int conflict(order* order1, order* order2){
    return (order1->startSeat <= order2->endSeat && order2->startSeat <= order1->endSeat);
}

// Returns 1 if the order pointed to by thisOrder can be added to the
// row pointed to by thisRow. thisNamely, 1 is returned if and only if
// thisOrder does NOT have any seats in it that are part of any order
// already on thisRow.
int canAddOrder(theaterrow* thisRow, order* thisOrder){
    for (int i = 0; i < thisRow->currentSize; i++){
        if(contains(thisRow->orders[i], thisOrder->startSeat) || contains(thisRow->orders[i], thisOrder->endSeat)){
            return 0;
        }
    }
    return 1;
}

// This function tries to add thisOrder to thisRow. If successful,
// the order is added and 1 is returned. Otherwise, 0 is returned and
// no change is made to thisRow. If the memory for thisRow is full,
// this function will double the maximum # of orders allocated for the
// row (via realloc), before adding thisOrder, and adjust maxSize and
// currentSize of thisRow.
void addOrder(theaterrow* thisRow, order* thisOrder){
    if (thisRow->currentSize == thisRow->maxSize){
        thisRow->maxSize *= 2;
        thisRow->orders = (order**) realloc(thisRow->orders, thisRow->maxSize * sizeof(order*));
    }
    thisRow->orders[thisRow->currentSize++] = thisOrder;
}

// If seatNum seat number in row number row is occupied, return a
// pointer to the owner’s thisName. Otherwise, return NULL.
char* getOwner(theaterrow** theater, int row, int seatNum){
    return getRowOwner(theater[row], seatNum);
}

// If seatNum in the row pointed to by thisRow is occupied, return a
// pointer to the string storing the owner’s thisName. If no one is sitting
// in this seat, return NULL.
char* getRowOwner(theaterrow* thisRow, int seatNum){
    for (int i = 0; i < thisRow->currentSize; i++){
        if(contains(thisRow->orders[i], seatNum))
            return thisRow->orders[i]->thisName;
    }
    return NULL;
}

// This function returns 1 if the seat number seatNo is contained in
// the range of seats pointed to by myorder, and returns 0 otherwise.
int contains(order* myorder, int seatNo){
    return (seatNo >= myorder->startSeat && seatNo <= myorder->endSeat);
}

// Frees all memory associated with thisOrder.
void freeOrder(order* thisOrder){
    free(thisOrder->thisName);
    free(thisOrder);
}

// Frees all memory associated with thisRow.
void freeRow(theaterrow* thisRow){
    for (int i = 0; i < thisRow->currentSize;i++){
        freeOrder(thisRow->orders[i]);
    }
    free(thisRow->orders);
    free(thisRow);
}