//COP3502 - Programming Assignment 1
//Katelyn Choudhari
//ka609383@ucf.edu

/*Problem: Given an original message and a new message the program counts how many of each character there is in a string.
Then it determines how many characters from the old message can be used to build the new message. Next, it is determined how
many more new characters will need to be purchased to complete the new message. It outputs both the old and new messages as
strings and outputs a single integer which is the count of characters that are still needed to complete the new message.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

int main(){
    //Dynamically allocate memory using malloc fnct for the two input strings
    char *original = (char *)malloc(100002 * sizeof(char));
    char *newMessage = (char *)malloc(100002 *sizeof(char));
    
    //If either string is NULL then output error message
    if (original == NULL || newMessage == NULL){
        printf("Memory allocation error\n");
        return 1;
    }

    //Use the fgets fnct to read in two strings (does not need to check if the characters are only uppercase letters and spaces)
    printf("Enter the original sign: \n");
    fgets(original, 100002, stdin);

    printf("Enter the newMessage sign: \n");
    fgets(newMessage, 100002, stdin);

    //Use two frequency arrays of characters where index 'i' will store the number of occurrences of the letter
    int freq1[26] = {0};
    int freq2[26] = {0};
    
    for (int i = 0; original[i] != '\0'; i++){
        char c = original[i];
        freq1[c - 'A']++;
    }

    for (int i = 0; newMessage[i] != '\0'; i++){
        char c = newMessage[i];
        freq2[c - 'A']++;
    }

    //Compare the frequencies of characters between both strings
    //Where i = 0 corresponds to A, i = 1 corresponds to B and so on
    int counter = 0;
    for (int i = 0; i < 26; i++){
        
    //Checks if the frequency in the new message is greater than the frequency in the original message
    //If so, more characters are required to complete the new message and the difference between them
    //represents the additional characters neeeded for the new message
        if (freq2[i] > freq1[i]){
            counter += freq2[i] - freq1[i];
        }
    }

    //Outputs both strings and a count of new characters needed, for the new message sign, as an integer
    puts(original);
    puts(newMessage);
    printf("%d", counter);

    //Memroy deallocation
    free(original);
    free(newMessage);
  
}